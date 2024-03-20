//modern C++ challenge - #6~10

#include<iostream>
#include<vector>

using namespace std;

//#1. ���׼� ���ϱ� : ���׼��� �ڽ��� ������ ������� ���� �ڽź��� ���� ���� �̾߱��Ѵ�.
//���׼��� ����1�� �ְ�, ���׼��� ������ ����2�� �־ �����Ѵ�. ��½� �� ���� ����ϵ��� �Ѵ�.
void iAbundance(int const iNum)
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

int main()
{
	/*iAbundance(20);*/
}