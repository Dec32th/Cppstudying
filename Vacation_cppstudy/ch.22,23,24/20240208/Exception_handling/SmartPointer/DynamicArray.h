#pragma once

//���� �迭 Ŭ����
class DynamicArray
{
public:
	//constructor, destructor
	DynamicArray(int arraySize);
	~DynamicArray();

	//accessor
	void SetAt(int index, int value);
	int GetAt(int index) const;
	int GetSize() const;

protected:
	int* arr;		//�Ҵ��� �޸� ����
	int size;		//�迭�� ���� ����
};