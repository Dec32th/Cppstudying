#include<list>
#include<iostream>
using namespace std;

int main()
{
	//int Ÿ���� ���� ��ũ�� ����Ʈ ����
	list<int> intList;

	//0-9���� ��ũ�� ����Ʈ�� �ִ´�
	for (int i = 0; i < 10; ++i)
	{
		intList.push_back(i);
	}

	//5�� ã�Ƽ� �����Ѵ�
	intList.remove(5);

	//��ũ�� ����Ʈ�� ������ ����Ѵ�
	list<int>::iterator it;
	for (it = intList.begin(); it != intList.end(); it++)
	{
		cout << *it << endl;
	}
}