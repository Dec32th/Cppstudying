//modern C++ challenge - #6~10

#include<iostream>
#include<vector>
#include<array>

using namespace std;

//#6. ���׼� ���ϱ� : ���׼��� �ڽ��� ������ ������� ���� �ڽź��� ���� ���� �̾߱��Ѵ�.
//���׼��� ����1�� �ְ�, ���׼��� ������ ����2�� �־ �����Ѵ�. ��½� �� ���� ����ϵ��� �Ѵ�.
void vAbundance(int const iNum)
{
	vector<int> vec1;	//���׼� ����
	vector<int> vec2;	//���׼��� ���� ����.

	if (iNum < 12)
	{
		cout << "There are no abundance in this range.";
	}
	else
	{
		for (int i = 12; i <= iNum; i++)
		{
			int iTotal = 1;
			for (int j = 2; j < i; j++)	//������� check.
			{
				if (i % j == 0)
				{
					iTotal += j;
				}
			}

			if (iTotal > i)
			{
				vec1.push_back(i);
				vec2.push_back(iTotal);
			}
		}
		for (int k = 0; k < vec1.size(); k++)
		{
			cout << "Abundance number(" << vec1[k] << ") : " << "abundance(" << vec2[k] <<")" << endl;
		}
	}
}

//#7 100������ ���� ģȭ���� ���ϱ� : ģȭ���� a�� �ڱ� �ڽ��� ������ ����� ���� b�� �ǰ� b�� ��쿡�� �� �ݴ밡 �Ǵ� ������ ������
//���� �����ϰ� �������� ���Ϳ� �־�ΰ� �� ���͸� �̿��ؼ� ���. ������ ����� �ϱ� ���ؼ� void������ ����

//20240321 ���� ���� ó������ �ʴ� ���ܰ� �߻�. ���� �ʿ�
void vAmicableNumber(int iNum)
{
	//100���� ����������, �Է¹��� ���� ������.
	if (iNum < 284)
		cout << "There are no amicable numbers in that range";
	else
	{
		//���⿡�� �ڱ� �ڽ��� ������ ����� ���� ���ϴ� �Լ��� ����Ѵ�. - 20240321 ����, �� �Լ��� �̿��� ���׼� �Լ��� ����.
		for (int i = 220; i <= iNum; i++)
		{

		}
	}
}

//�ڱ� �ڽ��� ������ ����� ���� ���ϴ� �Լ�, #6, 7���� ���ȴ�.
int iCalSum(unsigned int iNum)
{
	unsigned int iSum = 1;
	for (int j = 2; j < iNum; j++)
	{
		if (iNum % j == 0)
		{
			iSum += j;
		}
	}
	return iSum;
}

int main()
{
	/*vAbundance(20);*/
	/*vAmicableNumber();*/
}