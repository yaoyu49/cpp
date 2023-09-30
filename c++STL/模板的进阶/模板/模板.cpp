#include<iostream>
using namespace std;

template<class T>
bool IsEqual(T& left,T& right)
{
	return left == right;
}
//ģ����ػ�(���ĳЩ���͵����⻯����)
//�������ػ�
template<>
bool IsEqual<char*>(char*& left, char*& right)
{
	return strcmp(left,right) == 0;
}

//����ػ�
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

//ȫ�ػ�     ȫ���Ĳ�����Ҫ�ػ�����
template<>
class Data<int, char>
{
public:
	Data()
	{
		cout << "ȫ�ػ� Date<int,char>" << endl;
	}
private:

};

//ƫ�ػ�                           ע���������ǲ��ܰ�ƫ�ػ��������ػ���������
//�������ػ����ֲ�����Ҳ�����ǶԲ����Ľ�һ��������
template<class T1>
class Data<T1, int>
{
public:
	Data()
	{
		cout << "ƫ�ػ� Date<T1,int>" << endl;
	}
private:
};

template<class T1,class T2>                 //����ָ��Ҳ���Խ���ƫ�ػ�
class Data<T1*, T2*>                        
{
public:
	Data()
	{
		cout << "ƫ�ػ� Date<T1*,T2*>" << endl;
	}
private:
};

template<class T1, class T2>                 //����ָ��Ҳ���Խ���ƫ�ػ�
class Data<T1&, T2&>
{
public:
	Data()
	{
		cout << "ƫ�ػ� Date<T1&,T2&>" << endl;
	}
private:
};


int main()
{
	//char* p1 = "hello";
	//char* p2 = "misshuang";
	//cout << IsEqual(p1, p2) << endl;    �������һЩ���⣬notice
	Data<int, int> s1{};
	Data<int, char> s2{};
	Data<char, int> s3{};
	Data<char, char> s4{};
	Data<int*, int*> s5{};
	Data<char&, char&> s6{};
}