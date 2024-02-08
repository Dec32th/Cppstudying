#include"DynamicArray.h"
#include"MyException.h"

DynamicArray::DynamicArray(int arraySize)
{
	//�������� �޸𸮸� �Ҵ�
	arr = new int[arraySize];

	//�迭�� ���� ����
	size = arraySize;
}

DynamicArray::~DynamicArray()
{
	//�޸𸮸� ����
	delete[] arr;
	arr = 0;
}

//������ ���� �ٲ۴�
void DynamicArray::SetAt(int index, int value)
{
	if (index < 0 || index >= GetSize())
		throw MyException(this, "Out of Range!!!", index);
	arr[index] = value;
}

//������ ���� ��ȯ
int DynamicArray::GetAt(int index) const
{
	if (index < 0 || index >= GetSize())
		throw MyException(this, "Out of Range!!!", index);

	return arr[index];
}

//�迭�� ���� ��ȯ
int DynamicArray::GetSize() const
{
	return size;
}