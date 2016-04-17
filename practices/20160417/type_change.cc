 ///
 /// @file    type_change.cc
 /// @author  weinberg(553037372@qq.com)
 /// @date    2016-04-17 20:13:10
 ///
 
#include <iostream>

int main()
{
	using namespace std;
	double a;
	cin>>a;
	int b = static_cast<int>(a);
	cout<<b<<endl;
	return 0;
}
