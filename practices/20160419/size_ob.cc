 ///
 /// @file    size_ob.cc
 /// @author  weinberg(553037372@qq.com)
 /// @date    2016-04-19 22:45:17
 ///
 
#include <iostream>
using namespace std;

class size
{
private:
	int a;
	char b;
	float c;
	double d;
	short e[5];
	char &f;
	double &g;
	static int h;
public:
	size():f(b),g(d)
	{}
	
	void print()
	{
		cout<<"Hello"<<endl;
	}
};
int size::h = 0;

int main()
{
	size s;
	cout<<"sizeof(s) = "<<sizeof(s)<<endl;
	return 0;
}
