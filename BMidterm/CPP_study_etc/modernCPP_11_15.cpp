#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<array>
#include<utility>
#include<random>
#include<cmath>
#include<cstdlib>

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
//1���� 100������ �� �ؾ��ϹǷ� �Լ��� ���ſ�.
// 
//void vCollatz(unsigned int iLimit)
//{
//	vector<pair<int, long long>> vec1;
//	int iCount = 0;
//	for (int i = 1; i <= iLimit; i++)
//	{
//		if (i == 1)
//			vec1.push_back((make_pair(i, iCount)));
//		while (i != 1)
//		{
//			if (i % 2 == 0)
//			{
//				i /= 2;
//				iCount++;
//			}
//			else
//			{
//				i = i * 3 + 1;
//				iCount++;
//			}
//		}
//		
//	}
//	int iResult1 = vec1[0].first;
//	long long iResult2 = vec1[0].second;
//	for (auto elem : vec1)
//	{
//		if (iResult2 < elem.second)
//		{
//			iResult2 = elem.second;
//			iResult1 = elem.first;
//		}
//			
//	}
//	
//	int iNumber1 = iResult1;
//	while (iNumber1 != 0)
//	{
//			if (iNumber1 % 2 == 0)
//			{
//				cout << iNumber1 <<endl;
//				iNumber1 /= 2;
//				
//			}
//			else
//			{
//				cout << iNumber1 << endl;
//				iNumber1 = iNumber1 * 3 + 1;
//			}
//	}
//	cout << iResult2;
//}

pair<unsigned long long, long>longest_collatz(unsigned long long const limit)
{
	long length = 0;
	unsigned long long number = 0;
	vector<int> cache(limit + 1, 0);
	for (unsigned long long i = 2; i <= limit; i++)
	{
		auto n = i;
		long steps = 0;
		while (n != 1 && n >= i)
		{
			if ((n % 2) == 0)
				n = n / 2;
			else
				n = n * 3 + 1;
			steps++;
		}
		cache[i] = steps + cache[n];

		if (cache[i] > length)
		{
			length = cache[i];
			number += i;
		}
	}
	return make_pair(number, length);
}

//#13 ���� �� ����ϱ� 
//å������ ����� ���� �ٸ��� �ẻ��. 
// ���⼭�� �׷��� ���������� �޼��� ��� - 20240326����, ����� ������ �ϳ�, 
//while���� �ʹ� �������� ���Ƽ� ���� ���ѷ��������� �ð��� ���� �ɸ��� �� �ϴ�.
double dcompute_pi()
{
	double result = 4.;
	int iCount = 1;

	do
	{
		if (iCount % 2 != 0)
		{
			result -= 4. / ((2 * iCount) + 1);
			cout << result << endl;
			iCount++;
			cout << iCount << endl;
		}
		else
		{
			result += 4. / ((2 * iCount) + 1);
			cout << result << endl;
			iCount++;
			cout << iCount << endl;
		}

	} while (result != 3.1415926535);
	return result;
}


//#13 å�� �����ִ� ��� ���
template<typename E = mt19937,
	typename D = uniform_real_distribution<>>
	double compute_pi(E& engine, D& dist, int const samples = 1000000)
{
	auto hit = 0;
	for (auto i = 0; i < samples; i++)
	{
		auto x = dist(engine);
		auto y = dist(engine);
		if (y <= sqrt(1 - pow(x, 2))) 
			hit += 1;
	}
	return 4.0 * hit / samples;
}

//#14. ISBN ���� ���α׷� ���ϱ�
//�� 10�ڸ��� �̷������, ó������ ������ ���� 10-1�� ���ڸ� ���ϰ� �� ���� ������ �� ���ؼ� 11�� ����� �ǵ��� ������ ���ڸ� ���Ѵ�.
//bool���� �Լ��� �����ϰ�, �Է¹޴� ���� ���ڿ��̴�. ���ڿ��� ��� �����̰�, ��ȿ�� isbn�� ��, true�� ��ȯ�Ѵ�.
//20240328 ���� ���� �����ϴ� �� �ʿ��ϴ�!
bool is_isbn(string sStr)
{
	//���� ������ �ٲٱ� ���ؼ� �ʿ���.
	stringstream sString;

	//�ӽ÷� ���� ���� �����ϴ� int�� ����. ���� ���� �Լ� ���Ϳ� �ִ´�.
	int iNum = 0;

	//���� ���ڿ��� ���ڷ� ��ȯ�ϱ� ���� vector����, �ں��� �� ���ھ� �߶� �־��ش�. 
	vector<int> vec1;
	
	for (int i = 0; i < 10; i++)
	{
		//�ʱ�ȭ�� �ؾ� �ٸ� �������� ������ �����ϴ�.
		sString.str("");
		int iNum = 0;

		sString << sStr[i];
		cout << "sStr[i] : " << sStr[i] << endl;

		sString >> iNum;
		cout << "iNum : " <<iNum <<endl;

		vec1.push_back(iNum);
	}

	//isbn�� ���� ����� �� ������ üũ�ϱ� ���� int�� ���� ����ġ�� ���ؼ� �� ���� ������ �� ������ �Ǻ��Ѵ�. 
	int iSum = 0;
	for (int j = 10; j > 0; j--)
	{
		for (int k = 0; k < 10; k++)
		{
			iSum += vec1[k] * j;
			cout << "This is iSum : "<<iSum << endl;
		}
	}

	cout << iSum << endl;
	//11�� ����� ���, true ����
	if (iSum % 11 == 0)
		return true;

	//�׷��� ���� ���, false return
	else
		return false;

}

//#15. IPv4 ������ ���� ǥ���ϴ� �Լ� �ۼ��ϱ�
// �ܼ� ����� ���� �ּҸ� �а� �����. ������ ���еȰ� �Է�
// ��µ� ���� ��������
//?�ٵ� ��� �� ��� ��Ÿ����� ������ �� ���ذ� �Ȱ��µ�
class IPv4
{
public:

};


int main()
{
	/*cout << sToRomain(53) << endl;
	cout << sToRomain(83) << endl;
	cout << sToRomain(901) << endl;*/
	
	/*random_device rd;
	auto seed_data = array<int, mt19937::state_size> {};
	generate(begin(seed_data), end(seed_data), ref(rd));
	seed_seq seq(begin(seed_data), end(seed_data));
	auto eng = mt19937{ seq };
	auto dist = uniform_real_distribution<>{ 0,1 };

	for (auto j = 0; j < 10; j++)
		cout << compute_pi(eng, dist) << endl;
	*/

	cout <<is_isbn("8995432101");
	
	
}