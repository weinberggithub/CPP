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
	static int total_price;

public:
	Computer()//无参构造函数
	:price(0)
	{
		brand = new char[1];
		cout<<"调用无参构造函数"<<endl;
	}
	Computer(char *br,int pr)//调用有参构造函数
	:price(pr)
	{
		brand = new char[strlen(br) + 1];
		strcpy(brand,br);
		total_price += price;
		cout<<"调用有参构造函数"<<endl;
	}
	Computer(const Computer & pc)//复制构造函数
	{
		
		brand = new char[strlen(pc.brand) + 1];
		strcpy(brand,pc.brand);
		price = pc.price;
		total_price += price;
		cout<<"调用复制构造函数"<<endl;
	}
	Computer &operator=(const Computer &cp)
	{
		cout<<"赋值运算符重载函数被调用"<<endl;
		if(this == &cp)
			return (*this);
		price = cp.price;
		total_price += price;
		delete [] brand;
		brand = new char(strlen(cp.brand) + 1);
		strcpy(brand,cp.brand);
		cout<<"赋值运算符重载函数被调用"<<endl;
		return (*this);
	}
	static void total_print()
	{
		cout<<"total_price"<<total_price<<endl; 
	}
	static void print(Computer &cm)
	{
		cout<<"brand = "<<cm.brand<<endl;
		cout<<"price = "<<cm.price<<endl;
//		cout<<"toltal_price"<<total_price<<endl;
	}
	~Computer()//析构函数一旦定义之后，销毁对象的时候调用的也是用户自己显示定义的析构函数。
	{
		if(brand == NULL)
		{
			delete [] brand;
		}
		total_price -= price;
//		cout<<"total_price--"<<endl;
	}
};

int Computer:: total_price = 0;

int main()
{
	Computer pc((char*)"dell",40000);
	Computer:: print(pc);
	Computer:: total_print();

	Computer pc1(pc);
//	pc1 = pc;
	Computer:: print(pc1);
	Computer:: total_print();

#if 1
	Computer pc2(pc);
//	pc2 = pc1;
	pc2.~Computer();
	pc2.~Computer();
	Computer:: total_print();
#endif

	return 0;
}
