/*************************************************************************
    > File Name: intvert.c
    > Author: yutao
    > Mail: 1052249521@qq.com 
    > Created Time: Sun 15 Sep 2017 08:05:49 PM CST
 ************************************************************************/
 
 //简单的一个c语言实现多态
#include <stdio.h>  
#include <stdlib.h>

typedef void(*FUN)();//函数指针  
 
typedef struct Base//父类  
{  
    FUN fun;//通过函数指针访问外部函数  
    int a;  
}Base;  

typedef struct Son//子类  
{  
    Base base;//子类定义一个基类对象可实现对基类的继承  
    int b;  
}Son;  

void FunBase(Base* this)//父类函数  
{  
    printf("i am Base %d\n", this->a);  
}  
Base* newBase(Base* this, int a)//父类构造函数  
{
	this->fun = FunBase;
	this->a = a;
}


void FunSon(Son* this)//子类函数  
{  
    printf("i am son %d\n",this->b);  
}
Son* newSon(Son* this, int b)//子类构造函数  
{
	this->base.fun = FunSon;
	this->b = b;
}

void Test()  
{ 
	//正常调用
	Base b;
  	Base* pbase_ = newBase(&b, 10);
	printf("%d\n",pbase_->a);
	pbase_->fun(&b);

	//多态调用
	Son s;
	Base* p = (Base*)newSon(&s,20);
//	printf("%d\n",p->b);
	p->fun(&s);
} 

int main(int argc, char* argv[])
{  
    Test();  
	
    return 0;  
}  









