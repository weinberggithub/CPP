 ///
 /// @file    auto.cc
 /// @author  weinberg(553037372@qq.com)
 /// @date    2016-04-15 22:52:38
 ///
 
#include <iostream>

int main()
{
	using namespace std;
	auto a = 1;//注意auto关键字在使用的时候一定要先声明是什么了类型的，不能auto a;这样使用。但是为什么和书上的一样但是还是报错。
//	a = 'a';
//	cout<<"char a="<<a<<endl;
	cout<<"int a="<<a<<endl;
	return 0;
}
