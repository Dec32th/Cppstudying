#include"DynamicArray.h"

DynamicArray::DynamicArray(int arraySize)
{
	//�������� �޸𸮸� �Ҵ�
	arr = new int[arraySize];

	//�迭�� ���� ����
	size = arraySize;
}

DynamicArray::~DynamicArray()
{
	//�޸𸮸� �����Ѵ٤�.
	delete[] arr;
	arr = 0;
}

//������ ���� �ٲ۴�
void DynamicArray::SetAt(int index, int value)
{
	//�ε����� ������ ���� ������ ���ܸ� ������
	if (index < 0 || index >= GetSize())
	{
		throw "Out of Range!!!";
	}
	arr[index] = value;
}

//������ ���� ��ȯ�Ѵ�.
int DynamicArray::GetAt(int index) const
{
	if (index < 0 || index >= GetSize())
		throw "Out of Range!!!";
	return arr[index];
}

//�迭�� ���̸� ��ȯ
int DynamicArray::GetSize() const
{
	return size;
}