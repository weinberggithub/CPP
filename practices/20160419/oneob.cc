 ///
 /// @file    oneob.cc
 /// @author  weinberg(553037372@qq.com)
 /// @date    2016-04-19 23:10:02
 ///
 
#include <iostream>
using namespace std;

class Oneob
{
private:
	Oneob()//构造函数私有化，这样就保证只能在类里面创建对象。
	{
		cout<<"调用构造函数"<<endl;
	}
	~Oneob()
	{
		if(o != NULL)
		{
			delete o;
		}
		return 0;
	}
	static int _flag;
	static Oneob *o;//定义一个类类型的指针，用于传递指针和检测创建的对象是否只有一个
public:
	static Oneob * GetOb()//静态的获取对象的函数。
	{
		if(o == NULL)
		{
			o = new Oneob;
			_flag++;
			return o;
		}
		return o;
	}
	static destory(Oneob *one)
	{
		if(_flag == 1)
		{
			~Oneob();
		}
		one == NULL;
		_flag--;
	}
};

Oneob* Oneob::o = NULL;
int Oneob:: _flag = 0;

int main()
{
	Oneob *o1 = Oneob:: GetOb();
	destroy(o1);
	return 0;
}
