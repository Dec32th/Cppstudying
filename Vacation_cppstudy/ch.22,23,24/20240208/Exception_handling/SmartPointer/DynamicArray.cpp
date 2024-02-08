#include"DynamicArray.h"
#include"MyException.h"
#include<iostream>
using namespace std;

DynamicArray::DynamicArray(int arraySize)
{
	try
	{
		//�������� �޸𸮸� �Ҵ�
		arr = new int[arraySize];

		//�迭�� ���� ����
		size = arraySize;

		//���⼭ ���Ƿ� ���ܸ� �߻���Ų��.
		throw MemoryException(this, 0);
	}
	catch (...)
	{
		cout << "����� ����ȴ�." << endl;

		delete[] arr;

		throw;
	}
}

DynamicArray::~DynamicArray()
{
	try
	{
		//�޸𸮸� ����
		delete[] arr;
		arr = 0;
	}
	catch (...)
	{
	}

}

//������ ���� �ٲ۴�
void DynamicArray::SetAt(int index, int value)
{
	if (index < 0 || index >= GetSize())
		throw OutOfRangeException(this, index);
	arr[index] = value;
}

//������ ���� ��ȯ
int DynamicArray::GetAt(int index) const
{
	if (index < 0 || index >= GetSize())
		throw OutOfRangeException(this, index);

	return arr[index];
}

//�迭�� ���� ��ȯ
int DynamicArray::GetSize() const
{
	return size;
}