#include<iostream>
#include<vector>
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
	//���� ������ ���� ����
	int iSum = 0;
	
	//for���� ���ؼ� iNum���� �۰ų� ������ ������ 3�� ��� �Ǵ� 5�� ����� ����.
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
	//��Ŭ���� ȣ���� �̿�. 
	//iNum�� ���� 0�̸��� ���, ���� �� �����Ƿ� ����ó��
	if (iNum1 <= 0 || iNum2 <= 0)
	{
		cout << "there is wrong number.Please enter the right number.";
	}
	else
	{
		//parameter �߿��� �� ū ���� �Ǻ�, max min�� ����
		int iMax = iNum1 > iNum2 ? iNum1 : iNum2;
		int iMin = iNum1 > iNum2 ? iNum2 : iNum2;

		//��Ŭ���� ȣ����
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

//#2 +a �ִ����� ���ϱ� (��, ���ڰ� n�� ���� ��)

//#3 �ּҰ���� ���ϱ�
int iLcm(int iNum)
{
	int iCount;
	cin >> iCount;
	
	for (int i = 0; i < iCount; i++)
	{

	}
}

//#4 �־��� �� ������ ���� ū �Ҽ��� ���ϴ� �Լ�
int iMaxPrime(int iNum)
{
	//�Է¹��� ���� 2���� ������, ���� ū �Ҽ��� ����.
	if (iNum < 2)
	{
		cout << "there is a wrong input. Please enter the right input." << endl;
		return 0;
	}
	else
	{
		
		
		
	}
}

int main()
{
	//3�� 5�� ����� ���ϴ� �Լ��� �̿��ϱ� ���� ���� ����
	int iNum1 = 0;
	cout << "Please enter the maximum number to calculate multiple of 3 or 5.";
	cin >> iNum1;

	//�Լ��� �̿��� ���
	cout << "The answer is " << Sum3or5(iNum1) << endl;


	//GCD�Լ��� �̿��ϱ� ���� ��������
}