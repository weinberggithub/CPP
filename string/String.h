 ///
 /// @file    String.h
 /// @author  weinberg(553037372@qq.com)
 /// @date    2016-04-25 00:12:16
 ///
 
#include <iostream>

using namespace std;

class String {
	public:
			String();
			String(const char *);
			String(const String&);
			~String();

			String &operator=(const String &);
			String &operator=(const char *);

			String &operator+=(const String &);
			String &operator+=(const char *);

			char &operator[](size_t index);
			const char &operator[](size_t index) const;

			size_t size() const;
			const char* c_str() const;

			friend bool operator==(const String &, const String &);
			friend bool operator!=(const String &, const String &);

			friend bool operator<(const String &, const String &);
			friend bool operator>(const String &, const String &);
			friend bool operator<=(const String &, const String &);
			friend bool operator>=(const String &, const String &);

			friend ostream &operator<<(ostream &os, const String &s);
			friend istream &operator>>(istream &is, String &s);

	private:
			char *_pstr;
};

String operator+(const String &, const String &);
String operator+(const String &, const char *);
String operator+(const char *, const String &);
