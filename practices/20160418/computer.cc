 ///
 /// @file    computer.cc
 /// @author  weinberg(553037372@qq.com)
 /// @date    2016-04-18 11:50:25
 ///
 
#include <iostream>
#include<string.h>
using namespace std;

class computer//外部定义
{
public:
	void print();
//	{
//		cout<<"品牌："<<brand<<endl;
//		cout<<"价格："<<price<<endl;
//		cout<<"public i ="<<i<<endl;
//	}
	void setbrand(char *br);
	void setprice(double pr);
	int i;
private:
	char brand[20];
	double price;
//	void print();
//	protected:
//	int t;
};

void computer:: setbrand(char *br)
{
	strcpy(brand,br);
}
void computer:: setprice(double pr)
{
	price = pr;
}
void computer:: print()
{
	cout<<"品牌："<<brand<<endl;
	cout<<"价格："<<price<<endl;
//	cout<<"public i ="<<i<<endl;
}
//	class from_computer : protected computer{
//	public:
//		void print_t()
//		{
//			cout<<"t = "<<t<<endl;
//		}
//	};
class computer1//内部定义
{
public:
	void print()
	{
		cout<<"品牌："<<brand<<endl;
		cout<<"价格："<<price<<endl;
	}
	void setbrand(char *br)
	{
		strcpy(brand,br);
	}
	void setprice(double pr)
	{
		price = pr;
	}
private:
	char brand[20];
	double price;
};


int main()
{
	computer cp;
	cp.setbrand("samsung");
	cp.setprice(5000);
	cp.print();
	cp.i = 10;//公有成员是不能被访问还是什么问题？
//	cp.brand[20] = "qweqwre";//不能被访问
//	cout<<"cp.i ="<<cp.i<<endl;

//	from_computer fcp;
//	fcp.print();

	computer1 cp1;
	cp1.setbrand("dell");
	cp1.setprice(4000);
	cp1.print();
	return 0;
}
