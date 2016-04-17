 ///
 /// @file    new.cc
 /// @author  weinberg(553037372@qq.com)
 /// @date    2016-04-17 20:58:46
 ///
 
#include <iostream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

#ifdef __cplusplus
extern "C"
{
#endif
	void malloc_mem()
	{
		int i;
		char *a = (char*)malloc(10);
		strcpy(a,"drowolleh");
		printf("%s\n",a);
		free(a);
	}
#ifdef __cplusplus
}
#endif

void new_mem()
{
	using namespace std;
	char *a = new char*("hello word");
	int i;
//	for(i = 0;i < 10;i++)
//	{
		cout<<"*a = "<<a<<endl;//
//	}
	delete a;
}
int main(void)
{
	new_mem();
	malloc_mem();
	return 0;
}
