#pragma once

//封装string类
class Cmystring
{
	friend ostream& operator<<(ostream &out, const Cmystring& s);
	friend istream& operator<<(istream &in, const Cmystring& s)

public：
	//构造函数
	Cmystring( ); //无参构造
	Cmystring(const char* p); //有参构造
	Cmystring(const Cmystring& s); //拷贝构造函数

	//运算符重载
	Cmystring& operator=(const Cmystring& s);  //重载=
	Cmystring& operator=(const char* p);  //重载=
	bool operator==(const Cmystring& s);  //重载==
	bool operator==(const char* p);  //重载==
	bool operator!=(const Cmystring& s);  //重载!=
	bool operator!=(const char* p);  //重载!=
	Cmystring& operator+(const Cmystring& s);  //重载+
	bool operator<(const Cmystring& s);  //重载<号
	bool operator<(const char* p);	 //重载<号
	bool operator>(const Cmystring& s);  //重载>号
	bool operator>(const char* s);	 //重载>号
	char& operator[](int index) const;	//重载[]

	//转化 string to c风格字符串
	char* c_str();
	const char* c_str() const;

	//析构函数	   
	~Cmystring( );	 //析构函数

private:
	int 	m_len;
	char*	m_ptr;
	
}

