#include <iostream>
#include <cstring>
#include "mystring.h"

ostream& operator<<(ostream &out, const Cmystring& s);
{
	out << s.m_ptr;
	return out;
}

istream& operator<<(istream &in, const Cmystring& s)
{
	char tmp[1024] = {0};
	in >> tmp;
	if(s.m_ptr != NULL)
	{
		delete[] s.m_ptr;
		s.m_ptr = NULL;
	}

	s.m_len = strlen(tmp);
	s.m_ptr = new char[s.m_len + 1];
	strcpy(s.m_ptr, tmp);

	return in;
}

//构造函数
Cmytring::Cmystring( ):m_len(0) //无参构造
{
	m_ptr = new char[1];
	if(m_ptr == NULL)
	{
		cout << "err\n";
	}
	strcpy(m_ptr, ""); //赋空串
}

Cmytring::Cmystring(const char* p) //有参构造
{
	if(p == NULL)
	{
		m_len = 0;
		m_ptr = new char[1];
		if(m_ptr == NULL)
		{
			cout << "err\n";
		}
		strcpy(m_ptr, ""); //赋空串
	}
	else
	{
		m_len = strlen(p);
		m_ptr = new char[m_len + 1];
		memset(p, 0, m_len + 1);
		strcpy(m_ptr, p);
	}
}

Cmytring::Cmystring(const Cmystring& s) //拷贝构造函数
{
	m_len = s.m_len;
	m_ptr = new char[m_len + 1];

	strcpy(m_ptr, s.m_ptr);
}

//运算符重载
Cmystring& Cmytring::operator=(const Cmystring& s)  //重载=
{
	if(m_ptr != NULL)
	{
		delete[] m_ptr;
		m_ptr = NULL;
		m_len = 0;
	}
	
	m_len = s.m_len;
	m_ptr = new char[m_len + 1];
	strcpy(m_ptr, s.m_ptr);

	return *this;
}

Cmystring& Cmytring::operator=(const char* p)  //重载=
{
	if(m_ptr != NULL)
	{
		delete[] m_ptr;
		m_ptr = NULL;
		m_len = 0;
	}

	//
	if(p == NULL)
	{
		m_len = 0;
		m_ptr = new char[1];
		if(m_ptr == NULL)
		{
			cout << "err\n";
		}
		strcpy(m_ptr, ""); //赋空串
	}
	else
	{
		m_len = strlen(p);
		m_ptr = new char[m_len + 1];
		strcpy(m_ptr, p);
	}

	return *this;
}

bool Cmytring::operator==(const Cmystring& s)  //重载==
{
	if(m_len != s.m_len)
	{
		return false;
	}
	else if(strcmp(m_ptr, s.m_ptr))
	{
		return false;
	}

	return true;
}

bool Cmytring::operator==(const char* p)  //重载==
{
	if(p == NULL)
	{
		if(m_len == 0)
			return true;
		else
			return false;
	}
	else if(strcmp(m_ptr, p))
	{
		return false;
	}

	return true;
}

bool Cmytring::operator!=(const Cmystring& s) //重载!=
{
	return !(*this==s)
}

bool Cmytring::operator!=(const char* p)  //重载!
{
	return !(*this==p)
}

Cmystring& Cmytring::operator+(const Cmystring& s)  //重载+
{
	if(s.m_len == 0)
	{
		return *this;
	}
	else
	{
		int len = m_len + s.m_len;
		char* tmp = new char[len + 1];
		memset(tmp, 0, len + 1);
		strcat(tmp, m_ptr);
		strcat(tmp, s.m_ptr);
		{
			delete[] m_ptr;
			m_ptr = NULL;
			m_ptr = tmp;
			m_len = len;
		}

		return *this;
	}
}

bool Cmytring::operator<(const Cmystring& s)  //重载<号
{
	return strcmp(this->m_ptr, s.m_ptr);
}

bool Cmytring::operator<(const char* p)	 //重载<号
{
	return strcmp(this->m_ptr, p);
}

bool Cmytring::operator>(const Cmystring& s)  //重载>号
{
	return strcmp(this->m_ptr, s.m_ptr);
}

bool Cmytring::operator>(const char* s)	 //重载>号
{
	return strcmp(this->m_ptr, p);
}

char& Cmytring::operator[](int index) const 	//重载[]
{
	return this->m_ptr[index];
}

//转化 string to c风格字符串
char* Cmytring::c_str()
{
	return m_ptr;
}

const char* Cmytring::c_str() const
{
	return m_ptr;
}

//析构函数	   
~Cmytring::Cmystring( )	 //析构函数
{
	if(m_ptr != NULL)
	{
		delete[] m_ptr;
		m_ptr = NULL;
		m_len = 0;
	}
}

