 ///
 /// @file    computer.cc
 /// @author  weinberg(553037372@qq.com)
 /// @date    2016-04-18 11:50:25
 ///
 
#include <iostream>
#include<string.h>
using namespace std;

class point
{
public:
	
	point(int x,int y)
	{
		xpos = x;
		ypos = y;
	}
	point()//一旦重载构造函数之后，系统就不是默认调用了。
	{
		xpos = 0;
		xpos = 0;
	}
	void print();
private:
	int xpos;
	int ypos;
};

void point:: print()
{
	cout<<xpos;
	cout<<","<<ypos<<endl;
}

class point1{
public:
#if 0
	point1(int x,int y = -1)//构造函数的默认参数调用
	{
		xpos = x;
		ypos = y;
	}
#endif
#if 0
	point1(int x,int y)
		:xpos(x),ypos(y)//表达式初始化
	{
		cout<<"表达式初始化"<<endl;
	}
#endif
#if 1
	point1(int x,int y)//表达式初始化的顺序
		:xpos(y),ypos(y)
	{
		cout<<"表达式初始化的顺序"<<endl;
	}
#endif
	void print()
	{
		cout<<xpos;
		cout<<","<<ypos<<endl;
	}
private:
	int ypos;
	int xpos;
};
int main()
{
	point p1;
	p1.print();

	point p2(1,2);
	p2.print();

	point1 p3(-1,0);
	p3.print();
	return 0;
}
