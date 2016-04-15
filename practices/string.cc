 ///
 /// @file    string.cc
 /// @author  weinberg(553037372@qq.com)
 /// @date    2016-04-15 23:15:28
 ///
 
#include <iostream>
#include <string>

int main(int argc,char **argv)
{
	using namespace std;
	string str1 = "qwdfb    www";
	string str;
	int str2;
	cin>>str;
	cout<<str1<<endl;
	cin>>str;//首先cin遇到空格就会自动结束，但是空格后面的东西还在输入流里边
	cout<<str<<endl;
	cin>>str2;//神奇的是cin可以自动识别空格后面的int类型。意思是空格前边是字符串，后面是整型。所以cin自动将空格认为是一次结束。
	cout<<str2<<endl;//实验之后，发现空格后面的整型数确实可以打出来。

	//字符串拼接，string类型的数据可以直接用操作符+将其拼接起来。
	string string1 = "how are";
	string string2 = " you ?";
	string string3;
	string3 = string1 + string2;
	cout<<string3<<endl;
}
