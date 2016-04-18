 ///
 /// @file    string.cc
 /// @author  weinberg(553037372@qq.com)
 /// @date    2016-04-18 10:45:57
 ///

#include<string.h>
#include<stdlib.h>
#include <iostream>
#include<string>//为什么这里会跟下面的域作用符冲突？

//using std::cout
//using std::endl;
void str_cat()//sting类和char* 字符串拼接的区别
{
	using namespace std;
	char *ch1 = "hello";
	char *ch2 = "word";
	char *ch3 = (char*)malloc(10);
	strcat(ch3,ch1);
	strcat(ch3,ch2);
	cout<<"ch3 = "<<ch3<<endl;

	string str1 = "how ";
	string str2 = "are ";
	string str3 = "you?";

	string str4 = str1 + str2 + str3;
	cout<<"str4 = "<<str4<<endl;
}
void str_cut()//字符串剪切的区别
{
	using namespace std;
	
	int i;
	char *ch1 = "qwedddddqwe";
	char *ch2 = "ddddd";
	char *ch3 = (char*)malloc(5);
	strncpy(ch3,ch1+3,strlen(ch2));
	ch3 = strstr(ch1,ch2);
	for(i = 0;i < strlen(ch2);i++)
	{
		cout<<"ch["<<i<<"]"<<ch3[i]<<endl;
	}

	string str1 = "asdeeeeeasd";
	string str2 = "eeeee";
	string str3;
	int pos = str1.find(str2);
//	int len = strlen(str2);//不能使用，str2也不能转换。不知道为什么。
	str3 = str1.substr(pos,5);
	cout<<"str3 = "<<str3<<endl;
}

void str_arry()//string类的对象还可以使用下标操作符，但是下标操作符不检查错误
{
	using namespace std;
	string str = "12345";
	cout<<"str[5]"<<str[5]<<endl;//当越界的时候说是不会报错的。
	cout<<"str.at(5) = "<<str.at(5)<<endl;//这个时候会抛出一个异常，说at找不到5这个下标所在位置。越界了。
}
int main()
{
//	str_cat();
	str_cut();
//	str_arry();
	return 0;
}
