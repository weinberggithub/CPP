 ///
 /// @file    pointer.cc
 /// @author  weinberg(553037372@qq.com)
 /// @date    2016-04-19 16:58:38
 ///
 
#include <iostream>
#include<string.h>
	using namespace std;

class Pointer
{
public:
	Pointer(int x = 0,int y = 0)
	: xpos(x)
	, ypos(y)
	, ref1(xpos)
	, ref2(ypos)
	{
//		xpos = x;//静态成员初始化只能使用参数表达式，在构造函数里面赋值初始化编译不会通过的。
//		xpos = y;
	}
	Pointer(const Pointer &p)
	: xpos(p.xpos)
	, ypos(p.ypos)
	, ref1(xpos)
	, ref2(ypos)
	{
	// 复制构造函数也是一样，不能将静态成员在复制构造函数内部初始化	
	}
#if 0
	Pointer(int x = 0,int y = 0)
	{

	}
#endif
#if 0
	Pointer &operator=(const Pointer &p)//如果没有重载赋值运算符的话，那么对静态成员的初始化也会编译不过
										 //因为赋值运算符也是在函数内部进行的赋值。
										 //但是赋值函数不是构造函数不可以进行参数表达式赋值，所以在创建对象的时候不能先创建再用对象赋值。
										 
	{
		xpos = p.xpos;
		ypos = p.ypos;
	
		
	}
#endif
	void print()
	{
		sta = 1;//静态变量是可以进行写操作的，const关键字修饰的类型变成常类型，不能改变其值。
		cout<<"xpos = "<<xpos<<endl;
		cout<<"ypos = "<<ypos<<endl;
		cout<<"ref1 = "<<ref1<<endl;
		cout<<"ref2 = "<<ref2<<endl;
		cout<<"sta = "<<sta<<endl;
	}
private:
//	const int xpos;
//	const int ypos;
	int xpos;
	int ypos;
	int &ref1;
	int &ref2;
	static int sta;
};

int Pointer:: sta = 0;

int main()
{
	Pointer p1(1,2);
	p1.print();

	Pointer p2(p1);
	p2.print();

//	Pointer p3;
//	p3 = p1;
//	p3.print();

	return 0;
}
