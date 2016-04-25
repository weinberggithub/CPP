 ///
 /// @file    mylog.h
 /// @author  weinberg(553037372@qq.com)
 /// @date    2016-04-25 23:16:00
 ///
 
#ifndef __MYLOG_H__ 
 #define __MYLOG_H__ 
 #include <iostream> 
 #include <log4cpp/Category.hh> 
 #include <log4cpp/RollingFileAppender.hh> 
 #include <log4cpp/Priority.hh> 
 #include <log4cpp/PatternLayout.hh> 
 #include <log4cpp/OstreamAppender.hh> 
 #include <string> 
 using std::cout; 
 using std::endl; 
 using std::string; 
class Mylog{ 
public: 
	void warn(const char *msg); 
	void error(const char *msg); 
	void debug(const char *msg); 
	void info(const char *msg); 
	static Mylog * log; 
	static Mylog * openLog(); 
	static void closeLog(); 
private: 
	Mylog(); 
	~Mylog(); 
	log4cpp::Category * _category; 
}; 
void warn(const char *); 
void info(const char *); 
void debug(const char *); 
void error(const char *); 
#endif 

