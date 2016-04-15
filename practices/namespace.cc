 ///
 /// @file    namespace.cc
 /// @author  weinberg(553037372@qq.com)
 /// @date    2016-04-15 19:41:30
 ///
 
#include <iostream>
using namespace std;//编译指令。
extern int from_test = 1;//为什么不能调用test.cc里面的from_test?
int num = 0;//这个地方声明变量相当于声明一个全局变量。

namespace A{
	void usebyB()
	{
		cout<<"this is for test which is used by namespace B"<<endl;
	}
	void name_a()
	{
		cout<<"this is name_a in A"<<endl;
	}
}//end of A

namespace B{
	void name_a()
	{
		A::usebyB();
		cout<<"this is name_a in B"<<endl;
	}
}//end of B

namespace A{
	int num_A = 2;//名称空间可以在多个地方分开定义变量。
}//end of A

int main(int argc,char **argv)
{
//	using namespace std;//必要时将编译指令写在这个地方可以避免和函数里面的成员重名。
	A::name_a();
	B::name_a();
	cout<<"num = "<<num<<endl;
	cout<<"the extern num ="<<  ::from_test<<endl;//老师当时讲课的时候说，extern适用于不同模块之间共享变量的，也就是和说现在我在test.cc里面extern int from_test = 1;,再在namespace.cc里面调用from_test会得到test.cc里面的值。
//	A::cout_test();//在命名空间定义了与std名称空间cout同名的变量，由于编译指令是写在main里面的所以这个地方没有重名。但是好像实现不了。
}//end of main
