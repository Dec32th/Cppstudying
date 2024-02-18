#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	// ���� �迭�� �����ؼ� ������ �����ڸ� �߰�
	vector<char> vec;
	vec.push_back('e');
	vec.push_back('b');
	vec.push_back('a');
	vec.push_back('d');
	vec.push_back('c');

	//sort()�Լ��� ����ؼ� ����
	sort(vec.begin(), vec.end());

	//���� �� ���¸� ����Ѵ�
	cout << "vector ���� �� \n";
	vector<char>::iterator it;
	for (it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it;
	}
	cout << endl;

	//������ ���ڿ��� �־� ���� �迭 ����
	char arr[5] = { 'd', 'c', 'b', 'a', 'e'};

	//sort()�Լ��� ����ؼ� ����
	sort(arr, arr + 5);

	//���� �� ���� ���
	for (char* p = arr; p != arr + 5; ++p)
		cout << *p;
	cout << endl;
}