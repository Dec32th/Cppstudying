//modern C++ challenge - #6~10

#include<iostream>
#include<vector>
#include<cmath>
#include<string>
#include<bitset>

using namespace std;

//�ڱ� �ڽ��� ������ ����� ���� ���ϴ� �Լ�, #6, 7���� ���ȴ�.
int iCalSum(unsigned int iNum1)
{
	unsigned int iSum = 1;
	for (int j = 2; j < iNum1; j++)
	{
		if (iNum1 % j == 0)
		{
			iSum += j;
		}
	}
	return iSum;
}


//#6. ���׼� ���ϱ� : ���׼��� �ڽ��� ������ ������� ���� �ڽź��� ū ���� �̾߱��Ѵ�.
//���׼��� ����1�� �ְ�, ���׼��� ������ ����2�� �־ �����Ѵ�. ��½� �� ���� ����ϵ��� �Ѵ�.
// 
//20240322 ���� ���� �Ϸ�
void vAbundance(int const iNum)
{
	//vector<int> vec1;	//���׼� ����
	//vector<int> vec2;	//���׼��� ���� ����.

	//if (iNum < 12)
	//{
	//	cout << "There are no abundance in this range.";
	//}
	//else
	//{
	//	for (int i = 12; i <= iNum; i++)
	//	{
	//		int iTotal = 1;
	//		for (int j = 2; j < i; j++)	//������� check.
	//		{
	//			if (i % j == 0)
	//			{
	//				iTotal += j;
	//			}
	//		}

	//		if (iTotal > i)
	//		{
	//			vec1.push_back(i);
	//			vec2.push_back(iTotal);
	//		}
	//	}
	//	for (int k = 0; k < vec1.size(); k++)
	//	{
	//		cout << "Abundance number(" << vec1[k] << ") : " << "abundance(" << vec2[k] <<")" << endl;
	//	}
	//}

	if (iNum < 12)
		cout << "There are no abundance in that range.";
	else
	{
		for (int i = 12; i < iNum; i++)
		{
			if (iCalSum(i) > i)
			{
				cout << "Abundance number (" << i << ", " << iCalSum(i) << ")" << endl;
			}
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
		//���⿡�� �ڱ� �ڽ��� ������ ����� ���� ���ϴ� �Լ��� ����Ѵ�. 
		for (int i = 220; i <= iNum; i++)
		{
			int iTemp = iCalSum(i);

			if (i == iCalSum(iTemp) && i!=iTemp)
			{
				cout << "(" << i << ", " << iTemp << ")" << endl;
			}
		}
	}
}


//#8 �Ͻ�Ʈ�� �� ���ϱ� : �� �ڸ� �� �߿��� �� �ڸ��� ���� �������� ������ ���� ������ ���� �Ȱ��� ���� �Ͻ�Ʈ�� ����� �Ѵ�.
//����� �� �ֵ��� ���ϱ�. �׸��� �� ���� 100-999������ ������ ������.
void vAmstrongNumber()
{
	for (int i = 100; i < 1000; i++)
	{
		//100�� �ڸ����� 10�� �ڸ����� ���ϱ�
		int iHund = i / 100;
		int iTen = (i / 10) % 10;
		int iOne = i % 10;

		if (pow(iHund, 3) + pow(iTen, 3) + pow(iOne, 3) == i)
		{
			cout << "The number " << i << " is Amstrong Number." << endl;
		}
	}
}

//#8 ���μ����� ���α׷� �����ϱ�
void vprime_factor(int iNum)
{
	//���μ����ص� �ᱹ ����� ���ϴ� ��(1�� �ڱ� �ڽ��� ������ ����� ���Ѵٴ� ���̸� ����.)
	//�׷��Ƿ� ����� ���Ѵ�. 
	for (int i = 2; i * i <= iNum; i++)
	{
		while (iNum % i == 0)
		{
			cout << i << endl;
			iNum /= i;
		}
	}

	//������� �����ߴµ� �������� ���� ���. ���μ� ���ذ� �ȵȴٴ� ���̹Ƿ� �� ���� �Ҽ�.
	if (iNum > 1)
	{
		cout << iNum;
	}
	
}

//#10 �׷��� �ڵ� ��ȯ�ϱ�
//å ���� ���� 
unsigned int gray_encode(unsigned int const num)
{
	return num ^ (num >> 1);
}

unsigned int gray_decode(unsigned int gray)
{
	for (unsigned int bit = 1U << 31; bit > 1; bit >>= 1)
	{
		if (gray & bit) gray ^= bit >> 1;
	}
	return gray;
}


std::string to_binary(unsigned int value, int const digits)
{
	return std::bitset<32>(value).to_string().substr(32 - digits, digits);
}

int main()
{
	/*vAbundance(20);*/

	//ģȭ�� ���ϴ� ���α׷��� ���ſ�Ƿ� ���� �������� ����. - ����� �����ϴ� ���� Ȯ��.
	/*vAmicableNumber(100000000);*/

	/*vAmstrongNumber();*/

	/*vprime_factor(36);
	vprime_factor(16);
	vprime_factor(17);*/
	

	//#10 �׷����ڵ� ��ȯ
	cout << "Number\tbinary\tGray\tDecoded" << endl;
	cout << "------\t-----\t----\t------\n";
	
	for (unsigned int n = 0; n < 32; ++n)
	{
		auto encg = gray_encode(n);
		auto decg = gray_decode(encg);

		cout << n << "\t" << to_binary(n, 5) << "\t"
			<< to_binary(encg, 5) << "\t" << decg << endl;
	}
}