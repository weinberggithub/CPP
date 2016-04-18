 ///
 /// @file    cin.cc
 /// @author  weinberg(553037372@qq.com)
 /// @date    2016-04-18 11:50:02
 ///
 
#include <iostream>
#include<stdio.h>
#include<stdlib.h>

void scanf_c()
{
	char s;
	while(scanf("%c\n",&s))
	{
		printf("%c\n",s);
	}
}
void getlin_cpp()
{
	using namespace std;
	string s;
	while(getline(cin,s))
	{
		cout<<s<<endl;
	}
}
int main()
{
//	scanf_c();
	getlin_cpp();
	return 0;
}
