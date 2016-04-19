 ///
 /// @file    point.cc
 /// @author  weinberg(553037372@qq.com)
 /// @date    2016-04-19 22:16:56
 ///
 
#include <iostream>
using namespace std;

class Point
{
private:
	int xpos;
	int ypos;
public:
	Point(int x,int y)
	: xpos(x)
	, ypos(y)
	{
		cout<<"调用构造函数"<<endl;
	}
	
	Point()
	{
		xpos = 0;
		ypos = 0;
	}

	~Point()
	{
		cout<<"调用析构函数"<<endl;
	}
	void print()const
	{
	//	xpos = 1;
		cout<<"xpos"<<xpos<<endl;
		cout<<"ypos"<<ypos<<endl;
	}
};

int main()
{
#if 0
	Point p;
	p.print();//非const对象能修改成员的值
#endif

#if 0
	const Point p1;
	p1.print();//const对象不能修改成员的值，只能读取。错误显示：传递的const Point的this指针，缺少限定符
#endif
	
//	Point p[2];//没有合适的构造函数

//	Point p2[2] = {Point(1,2),Point(3,4)};//正确

//	Point p3[] = {Point(1,2),Point(3,4)};//自动确定数组大小。

//	Point p4[5] = {Point(1,2),Point(2,3)};//自动调用缺省构造函数
#if 0
	Point *p = new Point(4,5);
	cout<<"sizeof(p)"<<sizeof(p)<<endl;
	p->print();
	delete p;
	p=NULL;
#endif
	
	Point *p = new Point[3];
	cout<<"sizeof(p)"<<sizeof(p)<<endl;
	p->print();
//	delete p;//这个地方不用释放内存，释放对象的时候会自动释放，如果此处释放了会两次释放内存，因为这是一个数组
	p=NULL;


	return 0;
}
