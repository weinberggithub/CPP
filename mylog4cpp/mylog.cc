 ///
 /// @file    mylog.cc
 /// @author  weinberg(553037372@qq.com)
 /// @date    2016-04-25 23:22:09
 ///
 
 #include "mylog.h" 
 Mylog * Mylog::log = NULL; 
  Mylog::Mylog() 
	 { 
			_category = &(log4cpp::Category::getRoot().getInstance("Mylog")); 
			//layout for two appender 
			log4cpp::PatternLayout * ptl1 = new log4cpp::PatternLayout(); 
			ptl1->log4cpp::PatternLayout::setConversionPattern("%d:%p %c %x:%m%n");//%p priority 
			log4cpp::PatternLayout * ptl2 = new log4cpp::PatternLayout(); 
			ptl2->log4cpp::PatternLayout::setConversionPattern("%d:%p %c %x:%m%n"); 
							 
							 
			//two appender 
			log4cpp::RollingFileAppender * rfappender = new log4cpp::RollingFileAppender("rfappender","mylog.log",10*1024,1); 
			rfappender->setLayout(ptl1); 
			log4cpp::OstreamAppender * oappender = new log4cpp::OstreamAppender("oappender",&cout); 
			oappender->setLayout(ptl2); 
												 
			add them to our category 
			Mylog::_category->addAppender(rfappender); 
			Mylog::_category->addAppender(oappender); 
			Mylog::_category->setPriority(1000); 
	 } 
 Mylog * Mylog::openLog()
{ 
		if(NULL == Mylog::log)
		{ 
			log = new Mylog; 
			cout<<"Mylog is running"<<endl; 
		} 
			return log; 
} 
 Mylog::~Mylog(){ 
		_category->Category::shutdown(); 
		 } 
 void Mylog::closeLog(){//使用日志系统的都必须在结束处显示关闭 
		delete log; 
		 } 
 void Mylog::warn(const char *msg){ 
		_category->warn(msg); 
		 } 
 void Mylog::error(const char *msg){ 
		_category->error(msg); 
		 } 
 void Mylog::debug(const char *msg){ 
		_category->debug(msg); 
		 } 
 void Mylog::info(const char *msg){ 
		_category->info(msg); 
		 } 
 void warn(const char *msg){ 
		Mylog * log = Mylog::openLog(); 
			log->warn(msg); 
			 
			 
			 } 
 void error(const char *msg){ 
		Mylog * log = Mylog::openLog(); 
			log->error(msg); 
			 } 
 void debug(const char *msg){ 
		Mylog * log = Mylog::openLog(); 
			log->debug(msg); 
			 } 
 void info(const char *msg){ 
		Mylog * log = Mylog::openLog(); 
			log->info(msg); 
			 } 
