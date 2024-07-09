#include<iostream>
#include<string>
#include<sstream>
#include<numeric>
#include<vector>
#include<array>
#include<utility>
#include<random>
#include<cmath>
#include<cstdlib>
#include<assert.h>

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

//#14. å�� �ڵ�
//���� 14�� �ڵ�� sstream�� ���� �ʱ�ȭ�� ���� �ʾƼ� ����� ���� ������ �� ����! ���̷����� �𸣰ڴ�.
bool validate_isbn_10(string_view isbn)
{
	auto valid = false;
	if (isbn.size() == 10 &&
		count_if(begin(isbn), end(isbn), isdigit) == 10)
	{
		auto w = 10;
		auto sum = accumulate(
			begin(isbn), end(isbn), 0,
			[&w](int const total, char const c)
			{
				return total + w-- * (c - '0');
			});
		valid = !(sum % 11);
	}
	return valid;
}

//#15. IPv4 ������ ���� ǥ���ϴ� �Լ� �ۼ��ϱ�
// �ܼ� ����� ���� �ּҸ� �а� �����. ������ ���еȰ� �Է�
// ��µ� ���� ��������
//?�ٵ� ��� �� ��� ��Ÿ����� ������ �� ���ذ� �Ȱ��µ� - �ϴ� å�� �ڵ�� �Ʒ��� ����.

class ipv4
{
	array<unsigned char, 4> data;
public:
	constexpr ipv4() : data{ {0} } {}
	constexpr ipv4(unsigned char const a, unsigned char const b,
		unsigned char const c, unsigned char const d) : 
		data{{a,b,c,d}} {}
	explicit constexpr ipv4(unsigned long a) : 
		data{{static_cast<unsigned char>((a>>24)&0xFF),
			static_cast<unsigned char>((a>>16)&0xFF),
			static_cast<unsigned char>((a>>8)&0xFF),
			static_cast<unsigned char>(a&0xFF),
			}} {}
	ipv4(ipv4 const &other) noexcept : data(other.data) {}
	ipv4& operator=(ipv4 const& other) noexcept
	{
		data = other.data;
		return *this;
	}

	string to_string() const
	{
		stringstream sstr;
		sstr << *this;
		return sstr.str();
	}
	
	constexpr unsigned long to_ulong() const noexcept
	{
		return (static_cast<unsigned long>(data[0]) << 24) |
			(static_cast<unsigned long>(data[1]) << 16) |
			(static_cast<unsigned long>(data[2]) << 8) |
			static_cast<unsigned long>(data[3]);
	}

	friend ostream& operator<<(ostream& os, const ipv4& a)
	{
		os << static_cast<int>(a.data[0]) << '.'
			<< static_cast<int>(a.data[1]) << '.'
			<< static_cast<int>(a.data[2]) << '.'
			<< static_cast<int>(a.data[3]);

		return os;
	}

	friend istream& operator>>(istream& is, ipv4& const a)
	{
		char d1, d2, d3;
		int b1, b2, b3, b4;
		is >> b1 >> d1 >> b2 >> d2 >> b3 >> d3 >> b4;
		if (d1 == '.' && d2 == '.' && d3 == '.')
			a = ipv4(b1, b2, b3, b4);
		else
			is.setstate(ios_base::failbit);
		return is;

	}
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