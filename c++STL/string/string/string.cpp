#include<iostream>
using namespace std;
void test_string1()
{
	string s1("你好，我喜欢你");
	cout << s1 << endl;
}
void test_string2()
{
	string s("hello");
	s += " ";
	s += "world";
	cout << s << endl;
	//方法一:下标法
	for (size_t i = 0; i < s.size(); ++i)
	{
		cout << s[i] << " ";
	}
	cout << endl;
	//方法二:迭代器
	//string::const_iterator it = s.begin();
	 auto it = s.begin();
	//写
	while (it != s.end())
	{
		*it -= 1;
		cout << *it << " ";
		++it;
	}
	cout << endl;
	//读
	it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	//倒序遍历
	string::reverse_iterator rit = s.rbegin();
	while (rit != s.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
	//方法三:范围for
	for (auto ch : s)
	{
		cout << ch << " ";
	}
	cout << endl;
}

int stringzit(const string& str)
{
	int val = 0;
	string::const_iterator it = str.begin();
	while (it != str.end())
	{
		val *= 10;
		val += (*it - '0');
		++it;
	}
	return val;
}
void test_string3()
{
	string num("12345");
	cout << stringzit(num) << endl;;

}
void test_string4()
{
	char str1[] = "中国";
	cout << str1 << endl;
	str1[3] = -7;
	cout << str1 << endl;

}
void string3int(const string& str)
{
	size_t found = str.find('.');
	if (found != string::npos)
	cout << str.substr(found) << endl;
}
void test_string5()
{
	string s1("yaoyu.txt");
	string s2("yao.cpp");
	string s3("yu.h");

	string3int(s1);
	string3int(s2);
	string3int(s3);

}
//利用find
void string4int(const string& str)
{
	size_t found1 = str.find(':');
	if (found1 != string::npos)
		cout << str.substr(0,found1) << endl;
	size_t found2 = str.find('/', found1 + 3);
	    cout << str.substr(found1 + 3, found2 - (found1 + 3)) << endl;
		cout << str.substr(found2 + 1) << endl;
}
void test_string6()
{
	string url1("https://www.csdn.net/");
	string url2("https://cplusplus.com/reference/string/string/find/");
	//分离URL 协议 域名 资源名称
	string4int(url1);
	string4int(url2);
}
int main()
{
	cout <<"hello, world" << endl;
	test_string1();
	string s("12345");
	s.push_back('6');             //两种增加字符串的方法
	s.append("78");
	s += "5201314";               //推荐使用第三种，可读性很强
	cout << s << endl;

	//字符串转换为整形的操作
	string s2("12345");
	string s3("hello world", 2);
	string s4("Hello world", 1, 2);
	int val = 0;
	for (size_t i = 0; i < s2.size(); ++i)
	{
		val *= 10;
		val += (s2[i] - '0');
	}
	cout << val << endl;
	cout << s3 << endl;
	cout << s4 << endl;
	test_string2();
	test_string3();
	test_string4();
	test_string5();
	test_string6();
	return 0;
}