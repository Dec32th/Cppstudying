#include<iostream>
using namespace std;

class DynamicArray
{
public:
	int* arr;

	DynamicArray(int arraySize)
	{
		//�������� �޸𸮸� �Ҵ�
		arr = new int[arraySize];
	}
	~DynamicArray() //�Ҹ���. instance�� �Ҹ��ϸ鼭 ȣ��ǰ� �Ҹ�
	{
		delete[] arr;
		arr = NULL;
	}
};
int main()
{
	//�� ���� ������ �Է��� �� �����
	int size;
	cout << "�� ���� ������ �Է��Ͻðڽ��ϱ�?";
	cin >> size;

	//�ʿ��� ��ŭ�� �޸𸮸� �غ�
	DynamicArray da(size);

	

	//������ �Է¹޴´�
	for (int i = 0; i < size; ++i)
	{
		cin >> da.arr[i];
	}

	//�������� ���� ���
	for (int i = size - 1; i >= 0; --i)
	{
		cout << da.arr[i] << " ";
	}

	cout << endl;

	//���� �޸� �����G �ʿ� ����
}