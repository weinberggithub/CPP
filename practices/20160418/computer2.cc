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
		xpos = new int(sizeof(int));
		ypos = y;
	}
	point()//一旦重载构造函数之后，系统就不是默认调用了。
	{
		xpos = 0;
		xpos = 0;
	}
	~point()
	{
		cout<<"调用析构函数"<<endl;
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

int main()
{
	point p(1,2);
	return 0;
}
