#include<iostream>
#include<new>
using namespace std;

int main()
{
	try
	{
		//���� ���� �޸𸮸� �Ҵ�
		char* p = new char[0xfffffff0];
	}
	catch (bad_alloc& ex)
	{
		//������ bad allocation�̶�� ���� ����� ���� ����. ����...... -> �Ƹ��� �޸𸮰� �������� ������!!! 
		//��� �ؾ� �������� �𸣰ڴ�.
		cout << ex.what() << endl;
		cout << "���� ��µǳ���?";
	}
}