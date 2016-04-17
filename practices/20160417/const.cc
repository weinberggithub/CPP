 ///
 /// @file    const.cc
 /// @author  weinberg(553037372@qq.com)
 /// @date    2016-04-17 18:44:57
 ///
 
#include <iostream>

void const_test()
{
	using namespace std;
	const int a = 0;//const定义常量必须初始化，也就是说这个变量是不可变得。
	cout<<"a = "<<a<<endl;

	//常量指针
	int b;
	int b1;
	const int *p = &b;
	b = 1;
	b1 = -1;
	cout<<"*p(b) = "<<*p<<endl;
//	*p = 2;//指针常量的锁指对象的值是不能被改变的，所以这一语句解引用再赋值会报错。
	p = &b1;//但是常量指针是可以偏移的，也就是说可以将常量指针指向另一个变量。
	cout<<"*p(b1) = "<<*p<<endl;
	//指针常量
	int c;
	int c1;
	int * const q = &c;
	c = 2;
	cout<<"* q(c) = "<<*q<<endl;
	c1 = -2;
	p = &c1;
	cout<<"*q(c1) = "<<*q<<endl;//说明了指针常量是不可以偏移的
	*q = 10;
	cout<<"*q(c)"<<*q<<endl;//但是可以改变其指向的变量的值。
}

void pointer_to_const(const char *str1,const char *str2)//和所有C语言string库里面的函数一样，定义成常量指针就是不想传递的字符串在函数里面被改变。
{
	using namespace std;
	cout<<"str1 = "<<*str1<<endl;
	cout<<"str2 = "<<*str2<<endl;
	*str1 = "i wanna change str1";
	cout<<"str1(changed) = "<<*str1<<endl;//当调用这个函数时就会报错，显示read only的提示。

}

int main(void)
{
	char s1[] = "i am s1";
	char s2[] = "i am s2";
//	pointer_to_const(s1,s2);
	return 0;
}
