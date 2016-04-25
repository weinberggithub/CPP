 ///
 /// @file    main.cc
 /// @author  weinberg(553037372@qq.com)
 /// @date    2016-04-25 23:27:40
 ///
 
#include <iostream> 
 #include "mylog.h" 
 int main(){ 
	int i = 100; 
	while(--i){ 
		warn("lala"); 
		info("haha"); 
		error("gaga"); 
		debug("wawa"); 
			} 
	return 1; 
} 
