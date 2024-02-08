#include<iostream>
#include"DynamicArray.h"
#include"MyException.h"
#include<memory>
using namespace std;


void A();
void B();

int main()
{
	try
	{
		//DynamicArray�� �����ڿ��� ���� �߻�
		DynamicArray arr(100);
	}
	catch (MyException& ex)
	{
		cout << "���� ���� : " << ex.description << endl;
	}
}

void A()
{

	auto_ptr<char> ptr(new char[100]);

	cout << "���ܰ� �߻��ϱ� ��" << endl;

	//���ܸ� ������ �Լ� ȣ��
	B();

}

void B()
{
	throw "Exception!!";
}