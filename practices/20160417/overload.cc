 ///
 /// @file    overload.cc
 /// @author  weinberg(553037372@qq.com)
 /// @date    2016-04-17 20:18:45
 ///
 
#include <iostream>

int add(int a,int b)
{
	return a+b;
}

int add(int a,int b,int c)
{
	return a+b+c;
}

double add(double d,double e)
{
	return d + e;
}

int main()
{
	using namespace std;
	int a,b,c;
	double d,e;
	d = 1.2;
	e = 1.3;
	a = b = c = 1;
	cout<<"add(a,b) = "<<add(a,b)<<endl;
	cout<<"add(a,b,c) = "<<add(a,b,c)<<endl;
	cout<<"add(d,e) = "<<add(d,e)<<endl;
	return 0
}
//总结函数重载就是为了实现函数功能相似但是数据个数和数据类型各异。
