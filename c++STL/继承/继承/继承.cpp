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
	int _num;     //ѧ��
};
int main()
{
	//������Ը����������ָ�룬����   �и�
	Student s1;
	Person p1 = s1;      //����
	Person* p2 = &s1;    //ָ��
	Person& p3 = s1;     //����

	//s1 = p1;     ����Ķ����ǲ����Ը�������ģ����฽�ӵ����ݸ����޷�����

	//�����ָ�����ͨ��ǿ�Ƶ����͵�ת����������  ��������ָ������ָ���������
	p2 = &s1;
	Student* s2 = (Student*)p2;
	s2->_age = 20;

	//ת��ʱ�ǿ��Եģ����ǻ����Խ����ʵ�����
	p2 = &p1;
	Student* s3 = (Student*)p2;
	p2->_age = 30;
}