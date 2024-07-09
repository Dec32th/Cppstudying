#include<iostream>
#include<array>

using namespace std;

//array���� ã��, sizeOfArray�� �迭�� ũ��, value���� ã�´�.
//���� ��쿡�� ���� ����� ���� ���� return���ش�.
int BinarySearch(int array[], int sizeOfArray, int value)
{
	int midPoint;
	int First = 0;
	int Last = sizeOfArray - 1;

	while (First <= Last)
	{
		midPoint = (First + Last) / 2;

		if (array[midPoint] == value)
			return array[midPoint];

		else if (array[midPoint] < value)
		{
			First = midPoint + 1;
		}
		else
			Last = midPoint - 1;
	}
	return array[Last];

}

int main()
{
	int arr1[11] = { 1,2,4,5,7,10,12,14,15,19,30 };
	cout << BinarySearch(arr1, 11, 11) << endl;
}