 ///
 /// @file    string.cc
 /// @author  weinberg(553037372@qq.com)
 /// @date    2016-04-25 00:37:38
 ///
 
#include "String.h"
#include<string.h>

String:: ~String()
{
}
String:: String()
{
}
String & String::operator=(const char *ch)
{
	_pstr = new char(strlen(ch) + 1);
	strcpy(_pstr,ch);
	return (*this);
}

String & String:: operator=(const String &str)
{
	_pstr = str._pstr;
	return (*this);
}

String:: String(const char *ch)//char*有参构造
{
	_pstr = new char(strlen(ch) + 1);
	strcpy(_pstr,ch);
}

String:: String(const String &str)//String&有参构造
{
	_pstr = new char(strlen(str._pstr) + 1);
	_pstr = str._pstr;
}

String & String:: operator+=(const char *ch)//char*参数+=重载
{
	String tstr((*this));
	int lenth = strlen(_pstr) + strlen(ch) + 1;
	_pstr = new char(lenth);
	strcpy(_pstr,tstr._pstr);
	strcat(_pstr,ch);
	return (*this);
}
String & String:: operator+=(const String &str)
{
	(*this) += str._pstr;
	return (*this);
}

const char& String:: operator[](size_t index)const//这个函数的重载是根据用户可能出现的场景提供的，也就是说
												   //这个函数名传递给用户本函数的实现机制信息。
{
	if(strlen(_pstr) < index)
	{
		cout<<"error argc!"<<endl;
	}else{
		return _pstr[index - 1];
	}
}
char& String:: operator[](size_t index)
{
	if(strlen(_pstr) < index)
	{
		cout<<"error argc!"<<endl;//当越界的时候不知道处理，直接在函数体里面提示错误信息对于封装一个函数来说是不怎么合理的。
	}else{
		return _pstr[index - 1];
	}
}

size_t String:: size()const
{
	return strlen(_pstr);
}
const char* String:: c_str()const
{
	return _pstr;
}

String operator+(const String &str1,const String &str2)
{
	String str3(str1);
	str3 += str2;
	return str3;
}


String operator+(const String &str,const char *ch)
{
	String str1(str);
	str1 += ch;
	return str1;
}
String operator+(const char *ch,const String &str)
{
	String str1(str);
	str1 = str + ch;
	return str1;
}

ostream &operator<<(ostream &os,const String &s)
{
	os<<s._pstr;
	return os;
}

istream &operator>>(istream &is,String &s)
{
	is>>s._pstr;
	return is;
}

bool operator==(const String &str1,const String &str2)
{
	return !strcmp(str1._pstr,str2._pstr);
}

bool operator!=(const String &str1,const String &str2)
{
	return !(str1 == str2);
}

bool operator>(const String &str1,const String &str2)
{
		return strcmp(str1._pstr,str2._pstr) > 0 ? 1 :0;
}

bool operator<(const String &str1,const String &str2)
{
		return !(str1>str2);
}

bool operator>=(const String &str1,const String &str2)
{
	return str1 == str2 || str1 > str2 ? 1 : 0;
}
bool operator<=(const String &str1,const String &str2)
{
	return str1 == str2 || str1 < str2 ? 1 : 0;
}





int main()
{
	String str1= "1111111";
	String str2= "111111";

//	cout<<(str1 <= str2)<<endl;
//	str1 += str2;
//	cin>>str1;

	cout<<str1[100]<<endl;
//	cout<<str1.size()<<endl;
//	strlen(str1.c_str());//c_str()函数写成功。
//	cout<<(str1 == str2)<<endl;
#if 0
	if(str1 != str2)
	{
		cout<<"is not same"<<endl;
	}else
	{
		cout<<"is same"<<endl;
	}
#endif
	return 0;

}
