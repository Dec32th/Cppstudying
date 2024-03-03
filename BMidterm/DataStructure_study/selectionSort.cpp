//���� ���� �˰��� �Լ� coding - C++ �ڷᱸ����(2nd Edition) p.22

#include<iostream>
#include<array>
using namespace std;


//ũ�Ⱑ n�� �迭�� �Է� �ް� �� �迭�� ���鼭 a[i]�� ���� 
//a[j]�� ������ ũ��, a[j]�� a[i]�� ���� ��ġ�� �ٲ۴�.

void SelectionSort(int* a, const int n)
{
	//������ ���� �Է� ���� �ӽú��� temp ����
	int temp = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; ++j)
		{
			if (a[j] < a[i])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
			else
				continue;
		}
	}
}



int main()
{
	int arr[10] = { 10,9,8,7,6,5,4,3,2, 1 };

	//sizeof�� �迭�� ũ�⸦ ���ϰ�, �� ũ�⿡ ������ ũ�⸦ ���ؼ� �迭�� �����ϴ� byte ���� ���Ѵ�.
	int arr_size = sizeof(arr)/4;

	SelectionSort(arr, arr_size);

	for (int i = 0; i < arr_size; ++i)
	{
		std::cout <<"arr[" << i <<"] = " << arr[i] << " ,";
	}
	std::cout << endl;
}