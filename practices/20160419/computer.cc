 ///
 /// @file    computer.cc
 /// @author  weinberg(553037372@qq.com)
 /// @date    2016-04-19 10:35:35
 ///
 
#include <iostream>
#include<string.h>
using namespace std;

class Computer{
private:
	char * brand;
	int price;

public:
	Computer()//无参构造函数
	:price(0)
	{
		brand = new char[strlen(brand) + 1];
		cout<<"调用无参构造函数"<<endl;
	}
	Computer(char *br,int pr)//调用有参构造函数
	:price(pr)
	{
		brand = new char[strlen(br) + 1];
		strcpy(brand,br);
		cout<<"调用有参构造函数"<<endl;
	}
	Computer(const Computer & pc)//复制构造函数
	{
		brand = new char[strlen(pc.brand) + 1];
		strcpy(brand,pc.brand);
		price = pc.price;
	}
	Computer &operator=(const Computer &cp)
	{
		if(this == &cp)
			return (*this);
		price = cp.price;
		delete [] brand;
		brand = new char(strlen(cp.brand) + 1);
		strcpy(brand,cp.brand);
		cout<<"赋值运算符重载函数被调用"<<endl;
		return (*this);
	}
	void print()
	{
		cout<<"brand = "<<brand<<endl;
		cout<<"price = "<<price<<endl;
	}
};

int main()
{
	Computer pc("dell",40000);
	pc.print();

	Computer pc1;
	pc1 = pc;
	pc1.print();


}
