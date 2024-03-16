#include<iostream>
#include<vector>
#include<numeric>
#include<cmath>
#include<algorithm>
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
		if (i % 3 == 0 || i % 5 == 0)
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
		int iMin = iNum1 > iNum2 ? iNum2 : iNum1;

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
//å ���� �����ؼ� ����
//�ٵ� �� �ȸԴ��� �𸣰ڴ� �����!!!!!
int iLcm(int iNum1, int iNum2)
{
	//�� ���� �ִ������� ���Ѵ�. (������ 0�� �Է��� ������ 0�� �����ϰ�, �� ��쿡�� ���� �߸��Ǿ����� �� �� �ִ�.)
	int h = iGcd(iNum1, iNum2);
	return h ? iNum2 * (iNum1 / h) : 0;
}


//#4 �־��� �� ������ ���� ū �Ҽ��� ���ϴ� �Լ�
//å ���� �����ؼ� ����
int iMaxPrime(int iNum)
{
	bool primeCheck = true;
	//1. �Է� ���� ���� ���� �� ���缺 üũ
	if (iNum <=1)
	{
		cout << "Please enter the right number. That's wrong number.";
		return 0;
	}
	else if (iNum <= 3)
	{
		return iNum > 1;
	}
	else
	{
		for(int i = iNum; i>=2; i--)	//���鼭 i�� ���ؼ� ���������� ���� �Ҽ����� üũ�Ѵ�. i�� ���������� ��
		{
			for (int j = 2; j <= sqrt(iNum); j++)	//i�� ������ �� j. j�� ���������� ���� for���� break
			{
				if (i % j == 0)
				{
					primeCheck = false;
					break;
				}
			}
			if (primeCheck == true)
			{
				return i;
			}
		}
	}

	
}

//#5. ���üҼ� (�� �Ҽ����� ���� 6�� �Ҽ�) ���ϱ�
//#4���� �̿��� �Ҽ����� �˻��ϰ�, �� ������ 6���� ������ �˻�? �Ǵ� bool�� return�ϴ� �Լ��� �ϳ� ����� �� �Լ��� ���ؼ�?
int SixPrime(int iNum)
{
	int iCount6Prime = 0;
	if (iNum <11 )
	{
		cout << "Please enter the right number. That's a wrong number.";
		return 0;
	}
	else
	{

	}
}

int main()
{
	/*3�� 5�� ����� ���ϴ� �Լ��� �̿��ϱ� ���� ���� ����*/
	//int iNum1 = 0;
	//cout << "Please enter the maximum number to calculate multiple of 3 or 5." << endl;
	//cin >> iNum1;

	////�Լ��� �̿��� ���
	//cout << "The answer is " << Sum3or5(iNum1) << endl;


	//GCD�Լ��� �̿��ϱ� ���� ��������
	/*int iNum2, iNum3;
	cout << "Enter two numbers.";
	cin >> iNum2 >> iNum3;

	cout <<"The gcd is "<< iGcd(iNum2, iNum3);*/


	//lcm �Լ��� �̿��ϱ� ���� ���� ����
	int iLcmNum1, iLcmNum2;
	cout << "Enter two numbers for calculation of LCM : ";
	cin >> iLcmNum1 >> iLcmNum2;
	cout << "The LCM is " <<iLcm(iLcmNum1,iLcmNum2);
}