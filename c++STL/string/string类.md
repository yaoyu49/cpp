# string类

string类的一些用途

www.cplusplus.com

## 一.string常用的一些接口的用例

```c++
string str;
string s(str);
string s(str,strbegin,strlen);
string s(cstr,char_len);
string s(num,c);
string s(str,stridx);              //更多请参考C++官网文献

```

## 二.string的大小和容量



```c++
1.size()和length()：返回string对象的字符个数
2.max_size()：返回string对象最多包含的字符数
3.capacity():重新分配内存之前，string对象能包含的最大字符数
```

## 三.string的字符串比较

## 四.string的插入和拼接

**insert()和push_back()和+=以及append()**

```c++
string s("2345");
s.push_back('6');            
s.insert(s.begin(),'1');
s.append("78");
s += "5201314";               //推荐使用+=，可读性很强
cout << s << endl;
```

##五.string的遍历

**迭代器     下标法   for c++11**

```c++
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

```

## 六.string的删除:erase()

```c++
1. iterator erase(iterator p);//删除字符串中p所指的字符

2. iterator erase(iterator first, iterator last);//删除字符串中迭代器

区间[first,last)上所有字符

3. string& erase(size_t pos = 0, size_t len = npos);//删除字符串中从索引

位置pos开始的len个字符

4. void clear();//删除字符串中所有字符

```



## 七.string查找:find

```c++
1. size_t find (constchar* s, size_t pos = 0) const;

  //在当前字符串的pos索引位置开始，查找子串s，返回找到的位置索引，

    -1表示查找不到子串

2. size_t find (charc, size_t pos = 0) const;

  //在当前字符串的pos索引位置开始，查找字符c，返回找到的位置索引，

    -1表示查找不到字符

3. size_t rfind (constchar* s, size_t pos = npos) const;

  //在当前字符串的pos索引位置开始，反向查找子串s，返回找到的位置索引，

    -1表示查找不到子串

4. size_t rfind (charc, size_t pos = npos) const;

  //在当前字符串的pos索引位置开始，反向查找字符c，返回找到的位置索引，-1表示查找不到字符

5. size_tfind_first_of (const char* s, size_t pos = 0) const;

  //在当前字符串的pos索引位置开始，查找子串s的字符，返回找到的位置索引，-1表示查找不到字符

6. size_tfind_first_not_of (const char* s, size_t pos = 0) const;

  //在当前字符串的pos索引位置开始，查找第一个不位于子串s的字符，返回找到的位置索引，-1表示查找不到字符

7. size_t find_last_of(const char* s, size_t pos = npos) const;

  //在当前字符串的pos索引位置开始，查找最后一个位于子串s的字符，返回找到的位置索引，-1表示查找不到字符

8. size_tfind_last_not_of (const char* s, size_t pos = npos) const;

 //在当前字符串的pos索引位置开始，查找最后一个不位于子串s的字符，返回找到的位置索引，-1表示查找不到子串

```

## 八.getline()

c++中，cin的输入，遇到空格或者换行符时，结束输入，此时就要用到getline();

```c++
string s;
getline(cin,s);
```



## 完整代码

```c++
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
```

