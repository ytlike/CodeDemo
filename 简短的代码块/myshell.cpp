#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <vector>
#include <sys/wait.h>

#define _MAX_PIPE_NUM_  16
using namespace std;

//指令参数
struct CommandParams{
    string infile;//标准输入重定向
    string outfile;//标准输出重定向
    vector<string> v_argv;//参数列表
};

//拆分字符串的函数
void splitString(const char *Src,char delim,vector<string> &vsplit);

//解析指令的参数
void parseCommand(const char *srccmd,vector<CommandParams> &v_params)
{
    string srctmp = srccmd;
    vector<string> vstr_by_pipe;
	
    //按管道符号进行拆分
    if(srctmp.find('|') != string::npos)
    {
        splitString(srccmd,'|',vstr_by_pipe);
    }
    else
    {
        vstr_by_pipe.push_back(srctmp);//如果没有管道符号
    }
	
    //对管道拆分后的vector进行遍历拆分
    for(int i = 0 ; i < vstr_by_pipe.size();i ++)
    {
        CommandParams OneParams;
        string subCmd = vstr_by_pipe[i];//管道拆分后的子指令
        string OrgCmd = subCmd;//去掉重定向后的指令
		
        //先判断重定向符号和重定向的文件
        if(subCmd.find('<') != string::npos)
        {
            vector<string> vdupCmd;
            splitString(subCmd.c_str(),'<',vdupCmd);
            OneParams.infile = vdupCmd[1];//固定第二个元素是重定向的文件
            OrgCmd = vdupCmd[0];//去掉重定向后的指令
        }
		
        //先判断重定向符号和重定向的文件
        if(subCmd.find('>') != string::npos)
        {
            vector<string> vdupCmd;
            splitString(subCmd.c_str(),'>',vdupCmd);
            OneParams.outfile = vdupCmd[1];//固定第二个元素是重定向的文件
            OrgCmd = vdupCmd[0];//去掉重定向后的指令
        }
        cout<<"OrgCmd:"<<OrgCmd<<",infile:"<<OneParams.infile<<",outfile"<<OneParams.outfile<<endl;
		
        //对OrgCmd进行按空格拆分
        if(OrgCmd.find(' ') != string::npos)
        {
            vector<string> vtmp;
            splitString(OrgCmd.c_str(),' ',vtmp);
            OneParams.v_argv = vtmp;
        }
        else//没空格的情况
        {
            OneParams.v_argv.push_back(OrgCmd);
        }
        v_params.push_back(OneParams);//放到数组当中
    }
}

//执行指令的函数
void execCommand(vector<CommandParams> &v_params)
{
    int i =0;
    cout<<"func:"<<__FUNCTION__<<",line="<<__LINE__<<endl;
    for(i = 0; i < v_params.size() ; i ++)
    {
        cout<<"infile:"<<v_params[i].infile<<",outfile:"<<v_params[i].outfile;
        for(int j = 0; j < v_params[i].v_argv.size(); j ++)
        {
            cout<<" "<<v_params[i].v_argv[j];
        }
        cout << endl;

    }
	
    //计算需要的管道
    int pipenum = v_params.size() -1;
    int pipefd[_MAX_PIPE_NUM_][2];
    int j =0;
    for(i = 0; i < pipenum; i ++)
    {
        pipe(pipefd[i]);//初始化管道
    }
	
    //计算需要的线程
    for(i = 0; i < pipenum+1 ; i ++)
    {
        if(fork() == 0) break;//创建n个子进程
    }
	
    //用管道进行数据传递 i-1的输出传到管道的写端 传给 i 的输入是从管道的读端来
    //子进程的逻辑分三块
    if(i < pipenum +1)
    {
        if(i == 0)//第一个子进程
        {
            //close(pipefd[0][0]);
            dup2(pipefd[0][1],STDOUT_FILENO);//需要把标准输出重定向到管道

        }
        else if(i == pipenum)//最后一个子进程
        {
            dup2(pipefd[i-1][0],STDIN_FILENO);//重定向读端

        }
        else//中间子进程
        {
            dup2(pipefd[i-1][0],STDIN_FILENO);
            dup2(pipefd[i][1],STDOUT_FILENO);

        }
        //关闭未使用管道
        for(j = 0; j < pipenum; j ++)
        {
            close(pipefd[j][0]);
            close(pipefd[j][1]);
        }
        //代表有重定向输入
        if(v_params[i].infile.size() > 0)
        {
            int infd = open(v_params[i].infile.c_str(),O_RDONLY);
            if(infd < 0)
            {
                perror("open infile err");
                exit(1);
            }
            dup2(infd,STDIN_FILENO);//读标准输入重定向为读文件
            close(infd);
        }
        if(v_params[i].outfile.size() > 0)
        {
            int outfd = open(v_params[i].outfile.c_str(),O_WRONLY|O_CREAT|O_TRUNC,0664);
            if(outfd < 0)
            {
                perror("open outfile err");
                exit(1);
            }
            dup2(outfd,STDOUT_FILENO);//读标准输入重定向为读文件
            close(outfd);
        }
		
        //执行指令
        //生成参数列表
        char *r_argv[10];
        for(j = 0 ; j < v_params[i].v_argv.size() ; j ++)
        {
            r_argv[j] = (char*)v_params[i].v_argv[j].c_str();
        }
        r_argv[j] = NULL;//哨兵
        execvp(v_params[i].v_argv[0].c_str(),r_argv);//执行子进程
    }
    else
    {
        //关闭未使用管道
        for(j = 0; j < pipenum; j ++)
        {
            close(pipefd[j][0]);
            close(pipefd[j][1]);
        }
        for(i = 0; i < pipenum+1; i ++)
            wait(NULL);
        v_params.clear();
    }
}

int main(void)
{
    char buf[256];
    vector<CommandParams> vParams;
    while(1)
    {
        printf("myshell>");
        memset(buf,0x00,sizeof(buf));
        fgets(buf,sizeof(buf),stdin);

        //解析指令
        buf[strlen(buf)-1]='\0';
        printf("buf is %s\n",buf);
        parseCommand(buf,vParams);
        //执行指令
        execCommand(vParams);
    }
    return 0;
}

void splitString(const char *Src,char delim,vector<string> &vsplit)
{
    //upload test.cpp test.1 
    string tmp = Src;
    vsplit.clear();
    int index = 0,last = 0;
    index = tmp.find_first_of(delim,last);
    while(index != string::npos)//npos?????ַ????Ľ?β
    {
        vsplit.push_back(tmp.substr(last,index-last));
        last = index +1;
        index = tmp.find_first_of(delim,last);
    }
    //cout<<index<<","<<last<<endl;
    if(tmp.length() > last )
    {
        vsplit.push_back(tmp.substr(last));
    }
    //cout<<vsplit.size()<<endl;
    for(size_t i = 0; i < vsplit.size(); i ++)
    {
        cout<<"i="<<i<<","<<vsplit[i].c_str()<<endl;
    }
}
