#include<iostream>
#include<array>

using namespace std;

//array���� ã��, sizeOfArray�� �迭�� ũ��, value���� ã�� ���� ��쿡�� -1
int BinarySearch(int array[], int sizeOfArray, int value)
{
	int midPoint;
	int First = 0;
	int Last = sizeOfArray - 1;

	while (First<=Last)
	{
		midPoint = (First + Last) / 2;

		if (array[midPoint] == value)
			return midPoint;

		else if (array[midPoint] < value)
		{
			First = midPoint + 1;
		}
		else
			Last = midPoint - 1;
	}

	return -1;
}

int main()
{
	int arr1[7] = { 1,2,5,6,8,10,15 };
	cout << BinarySearch(arr1, 7, 5) <<endl;
	cout << BinarySearch(arr1, 7, 10) <<endl;
	cout << BinarySearch(arr1, 7, 4) <<endl;
}