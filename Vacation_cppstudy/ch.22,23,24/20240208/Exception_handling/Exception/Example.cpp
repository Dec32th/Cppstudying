#include"DynamicArray.h"
#include"MyException.h"
#include<iostream>
using namespace std;

void UseArray(DynamicArray& arr1, DynamicArray& arr2);

int main()
{
	//�迭 ��ü 2�� ����
	DynamicArray arr1(10);
	DynamicArray arr2(8);

	UseArray(arr1, arr2);

}

void UseArray(DynamicArray& arr1, DynamicArray& arr2)
{
	try
	{
		arr1.SetAt(5, 100);
		arr2.SetAt(5, 100);

		arr1.SetAt(8, 100);
		arr2.SetAt(8, 100);

		arr1.SetAt(10, 100);
		arr2.SetAt(10, 100);
	}
	catch(MyException& ex)
	{
		//�� �迭�� �ּҸ� ���� ���
		cout << "&arr1 = " << &arr1 << "\narr2 = " << &arr2 << endl;

		//���ܿ� ���� �ڼ��� ���� ���
		cout << "���ܸ� ���� ��ü�� �ּ� = " << ex.sender << endl;
		cout << "���ܿ� ���� ���� = " << ex.description << endl;
		cout << "�ΰ� ���� = " << ex.info << endl;
	}
}