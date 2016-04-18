 ///
 /// @file    mem.cc
 /// @author  weinberg(553037372@qq.com)
 /// @date    2016-04-18 20:55:52
 ///
 
#include <iostream>

int a = 0;//全局区
const int b = 1;//常量区
int main()
{
	using namespace std;
	int c = 2;//栈
	const int d = 3;//常量区
	int *e = &c;//指针e是储存在栈里面
	int *f = new int(4);//f储存在栈里面，f指向堆内存。
	char *g = "123456789";//常量区的只读段是不能被改变的。

	cout<<"&a= "<<&a<<endl;
	cout<<"&b= "<<&b<<endl;
	cout<<"&c= "<<&c<<endl;
	cout<<"&d= "<<&d<<endl;
	cout<<"&e= "<<&e<<endl;
	cout<<"e= "<<e<<endl;
	cout<<"&f= "<<&f<<endl;
	cout<<"f= "<<f<<endl;
}
