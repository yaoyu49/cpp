#include<iostream>
using namespace std;
class Person
{
public:
	string _name;
	string _sex;
	int _age;
};
class Student : public Person
{
public:
	int _num;     //学号
};
int main()
{
	//子类可以赋给父类对象，指针，引用   切割
	Student s1;
	Person p1 = s1;      //对象
	Person* p2 = &s1;    //指针
	Person& p3 = s1;     //引用

	//s1 = p1;     基类的对象是不可以赋给子类的，子类附加的内容父类无法给予

	//父类的指针可以通过强制的类型的转换付给子类  这个父类的指针有是指向子类对象
	p2 = &s1;
	Student* s2 = (Student*)p2;
	s2->_age = 20;

	//转换时是可以的，但是会存在越界访问的问题
	p2 = &p1;
	Student* s3 = (Student*)p2;
	p2->_age = 30;
}