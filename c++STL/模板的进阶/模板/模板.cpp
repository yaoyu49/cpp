#include<iostream>
using namespace std;

template<class T>
bool IsEqual(T& left,T& right)
{
	return left == right;
}
//模板的特化(针对某些类型的特殊化处理)
//函数的特化
template<>
bool IsEqual<char*>(char*& left, char*& right)
{
	return strcmp(left,right) == 0;
}

//类的特化
template<class T1,class T2>
class Data
{
public:
	Data()
	{
		cout << "Date<T1,T2>" << endl;
	}
private:
	T1 _d1;
	T2 _d2;
};

//全特化     全部的参数都要特化处理
template<>
class Data<int, char>
{
public:
	Data()
	{
		cout << "全特化 Date<int,char>" << endl;
	}
private:

};

//偏特化                           注意这里我们不能把偏特化叫做半特化，看下面
//可以是特化部分参数，也可以是对参数的进一步的限制
template<class T1>
class Data<T1, int>
{
public:
	Data()
	{
		cout << "偏特化 Date<T1,int>" << endl;
	}
private:
};

template<class T1,class T2>                 //这里指针也可以叫做偏特化
class Data<T1*, T2*>                        
{
public:
	Data()
	{
		cout << "偏特化 Date<T1*,T2*>" << endl;
	}
private:
};

template<class T1, class T2>                 //这里指针也可以叫做偏特化
class Data<T1&, T2&>
{
public:
	Data()
	{
		cout << "偏特化 Date<T1&,T2&>" << endl;
	}
private:
};


int main()
{
	//char* p1 = "hello";
	//char* p2 = "misshuang";
	//cout << IsEqual(p1, p2) << endl;    这里存在一些问题，notice
	Data<int, int> s1{};
	Data<int, char> s2{};
	Data<char, int> s3{};
	Data<char, char> s4{};
	Data<int*, int*> s5{};
	Data<char&, char&> s6{};
}