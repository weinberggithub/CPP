 ///
 /// @file    text_query.cc
 /// @author  weinberg(553037372@qq.com)
 /// @date    2016-05-01 20:44:10
 ///
 
#include <iostream>
#include<string>
#include<fstream>
#include<string.h>
#include<map>
#include<set>
#include<sstream>
#include<vector>

using namespace std;


class File
{

private:
		map<string,multiset<int> > map_words;
		vector<string> vec_line;
public:

	File(string text_name)//干脆在创建对象的时候将文件处理完成。
	{
		read_file(text_name);
	}

	bool read_file(string text_name);
	void save_line(string lincontent);
	bool save_words(int line_num,string lincontent);
	void print(string search_name);

};

bool File:: read_file(string text_name)
{
	int line_num = 0;
	ifstream ifs(text_name.c_str());
	string str;
	if(!ifs.good())
	{
		cout<<"open fial"<<endl;
		return false;
	}
	while(getline(ifs,str))
	{
		line_num++;
		save_line(str);		//将读取到的行存储
		save_words(line_num,str);//将行号和内容传进去，分解成单个单词记录行号
	}
}

void File:: save_line(string linecontent)//将传进来的行号和内容存进map内。
{
	vec_line.push_back(linecontent);
}

bool File:: save_words(int num,string linecontent)//将传进来的一行内容分解成单词，并存入set内。
{
	istringstream iss(linecontent);
	string single_wds;
	while(iss >> single_wds)
	{
		map<string,multiset<int> >::iterator it;
		it = map_words.find(single_wds);
		if(it == map_words.end())
		{
			pair<string,multiset<int> > p;
			p.first = single_wds;
			p.second.insert(num);
			map_words.insert(p);//没找到就插入新的元素。
		}else
		{
			//如果map里面存在就将行号存在set里面。
			it->second.insert(num);
		}
	}

}


void File:: print(string search_name)
{
	map<string,multiset<int> >:: iterator s_ret = map_words.find(search_name);//s_ret接收find返回的迭代器
	set<int>:: iterator s_setret;//用于s_ret中第二个元素set<int>的迭代器。
	int before_flag = 0;//记录s_setret遍历时的前一个元素的值，用于去除相同元素。
	if(s_ret != map_words.end())
	{
		s_setret = s_ret->second.begin();
		cout<<"word: "<<search_name<<"  count: "<<s_ret->second.size()<<endl;//打印单词和词频


//		before_flag = *s_setret;
		while(s_setret != s_ret->second.end())
		{
			if(before_flag != *s_setret)
			{
				cout<<"Line_No: "<<*s_setret<<" Line_Content: "<<vec_line[(*s_setret) - 1]<<endl;//打印所在行和该行内容。
			}
			before_flag = *s_setret;
			s_setret++;
		}
	}else
	{
		cout<<"The word you searched is not existing in this text."<<endl;
	}

}


#if 0
int main()
{
	string textname = "chinadaily.txt";
	string word_name;
	File file;
	file.read_file(textname);
	cin >> word_name;
	file.print(word_name);

	return 0;
}
#endif


#if 1
int main()//在执行函数时要求输入要读取的文本
{
//	char ch;
	string text_name;
	string word_name;
	cout<<"Please enter text name: "<<endl;
	cin >> text_name;
	File file(text_name);//在创建对象完成就将文件读取完毕。
//	file.read_file(text_name);
	cout<<"Enter a word to query(or Q to quit): "<<endl;
	while(cin >> word_name && word_name != "Q")//Q退出，输入单词就查询。
	{
		file.print(word_name);
	}


	return 0;
}

#endif




