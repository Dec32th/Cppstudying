#include<iostream>
using namespace std;

//morden C++ challenge source code coding - function fowm 
// 2024/03/12 - #1-5

//#1
//�Է¹��� �������� ���ڱ��� 3�� 5�� ����� ��� ���ϴ� �Լ�
//Moden C++ challenge å ������ �ڵ�

//Using namespace std; �� ���� �Լ��� ������ ��� ����.
//1 - 5���� �Լ��� ����� �� �Լ��� ������ �ڵ���.

//#1	3�̳� 5�� ������ �������� �� ���ϱ�
int Sum3or5(int iNum)
{
	int iSum = 0;
	for (int i = 1; i <= iNum; i++)
	{
		if(i % 3 == 0 || i % 5 == 0)
		{
			iSum += i;
		}
	}
	return iSum;
}


//#2	�ִ����� ���ϱ� - recursive function �̿�
int iGcd(int iNum1, int iNum2)
{
	int iMax = iNum1 > iNum2 ? iNum1:iNum2;
	int iMin = iNum1 > iNum2 ? iNum2:iNum1;


	if (iNum1 <= 0 || iNum2 <= 0)
	{
		cout << "there is wrong number.Please enter the right number.";
	}
	else
	{
		iMax = iNum1 > iNum2 ? iNum1 : iNum2;
		iMin = iNum1 > iNum2 ? iNum2 : iNum2;

		if (iMax % iMin == 0)
		{
			return iMin;
		}

		else
		{
			iGcd(iMin, iMax % iMin);
		}
	}
}

//#3 �ּҰ���� ���ϱ�
int iLcm(int iNum)
{
	int iCount;
	cin >> iCount;

	for (int i = 0; i < iCount; i++)
	{

	}
}

int main()
{

}