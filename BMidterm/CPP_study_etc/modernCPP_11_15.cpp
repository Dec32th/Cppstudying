#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<utility>

using namespace std;


//#11. �θ����� ǥ��� - unsigned const int�� �Է¹ް�, �� �Է¹��� ���� string������ �ٲ㼭 ��ȯ�Ѵ�.
//��, ������ ǥ����� �ϸ� �ʹ� ���������Ƿ� 4000�� ��� ivM���� ǥ���Ѵ�.
//20240325 å ����
string sToRomain(int iNum)
{
	//�� �־� ��� �����ϴ� vector. ù ��°�� int, �� ��°�� ���ڿ�.
	vector < pair<int, string>> vec1 = { {1000,"M"} ,{900,"CM"},{500,"D"},{400,"CD"},{100,"C"},{90,"XC"},{50,"L"},{40,"XL"}, {10,"��"},{9,"��"}, 
		{8,"��"},{7,"��"},{6,"��"},{5,"��"},{4,"��"}, {3,"��"}, {2,"��"},{1,"��"}};
	
	string sResult = "";
	int iNumber = iNum;

	//���� �Ǵ� �� ����.
	for (auto elem : vec1)
	{
		while (iNumber >= elem.first)
		{
			sResult += elem.second;
			iNumber -= elem.first;
		}
	}

	return sResult;
}

//#12. ���� �� �ݶ��� ���� �����ϱ� - ���
//�鸸 ������ ������, ��ȯ�� ���ؼ� ���� ���� ������ �ؼ� ��ȯ�� ���� ã��, �� ���� ��������� ����ϸ� �ȴ�..
//1���� 100������ �� �ؾ��ϹǷ� �Լ��� ���� ���ſ�.
void vCollatz(unsigned int iLimit)
{
	vector<pair<int, long long>> vec1;
	int iCount = 0;
	for (int i = 1; i <= iLimit; i++)
	{
		if (i == 1)
			vec1.push_back((make_pair(i, iCount)));
		while (i != 1)
		{
			if (i % 2 == 0)
			{
				i /= 2;
				iCount++;
			}
			else
			{
				i = i * 3 + 1;
				iCount++;
			}
		}
		
	}
	int iResult1 = vec1[0].first;
	long long iResult2 = vec1[0].second;
	for (auto elem : vec1)
	{
		if (iResult2 < elem.second)
		{
			iResult2 = elem.second;
			iResult1 = elem.first;
		}
			
	}
	
	int iNumber1 = iResult1;
	while (iNumber1 != 0)
	{
			if (iNumber1 % 2 == 0)
			{
				cout << iNumber1 <<endl;
				iNumber1 /= 2;
				
			}
			else
			{
				cout << iNumber1 << endl;
				iNumber1 = iNumber1 * 3 + 1;
			}
	}
	cout << iResult2;
}

int main()
{
	/*cout << sToRomain(53) << endl;
	cout << sToRomain(83) << endl;
	cout << sToRomain(901) << endl;*/


}