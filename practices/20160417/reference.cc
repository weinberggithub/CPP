 ///
 /// @file    refernce.cc
 /// @author  weinberg(553037372@qq.com)
 /// @date    2016-04-17 17:32:41
 ///
 
#include <iostream>

void ref()//这个程序演示了应用就是其指向的变量的一个别名。当改变原名和别名都将变量本身的值。
{
	using namespace std;
	int a;
	int & ref_a = a;
	int *p = &ref_a;
	a = 1;
	cout<<"ref_a = "<<ref_a<<endl;
	ref_a = 2;
	cout<<"a = "<<a<<endl;
	cout<<"&a = "<<&a<<endl;
	cout<<"&ref_a = "<<&ref_a<<endl;
	cout<<"*p = "<<*p<<endl;
}

void pass_ref(int &ref)//传引用
{
	using namespace std;
	cout<<"ref = "<<ref<<endl;
	ref = -1;
	cout<<"ref(changed) = "<<ref<<endl;
}
int main(void)
{
	ref();
	int a = 1;
	int &ref = a;
//	pass_ref(ref);
	return 0;
}
