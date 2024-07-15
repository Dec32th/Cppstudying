#include<iostream>
#include<array>
#include<string>
#include<sstream>
#include<vector>
using namespace std;

//�� �ڸ��� 0-255������ ���ڸ����� �Ǿ�������, .���� ������
//0-255�� �Ǿ��ְ�, 1.0.0.1 ���� 255.255.255.255���� �����ϴ�. -> �Է��� string ���� �޾Ƽ� ¥����!!!
//thtrow catch ������ �̿��ؼ� �̻��� ���� �ԷµǾ��� ��츦 ����Ѵ�. 

const int MAX_IPV4_SIZE = 4;

class IPv4
{
public:
	IPv4() {};
	IPv4(string ipstr) 
	{ 
		makeIPArray(ipstr); 
		ipv4Size = size(aIPv4);
	};
	//�Է� ���� string�� �迭�� �ִ� �Լ� -> �̶�, .�� �������� ������ �־��Ѵ�. 
	void makeIPArray(string IpNum);

	//����� ���� print �Լ�
	void Print();
	
	//���̿� �����ϴ� IP�� ���� ����ϴ� �Լ�. 
	void InterIP(IPv4 ip1);
	
private:
	int aIPv4[MAX_IPV4_SIZE];		//�迭���� ���ڸ� ����ȴ�. print�� �� ���� ���̿�.�� �־ ����������.
	int ipv4Size;
};



// �ϴ� �Է� ���� ���ڸ� .�� �������� �߶���Ѵ�. ��ġ�� �� ���� �迭�� �ִ� �� �ʿ���. 
// ���⿡ throw catch ������ �־ ������ ������ ��� 
void IPv4::makeIPArray(string ipNum)
{
	istringstream ss(ipNum);
	string temp1;
	vector<string> v1;

	while (getline(ss, temp1, '.'))
	{
		v1.push_back(temp1);
	}

	for (auto iter = v1.begin(); iter != v1.end(); iter++)
	{
		int i = 0;
		string temp = *iter;
		int temp1 = stoi(temp);
		aIPv4[i] = temp1;
		i++;
	}
}

void IPv4::Print()
{
	for (int i = 0; i < MAX_IPV4_SIZE; i++)
	{
		if (i == 3)
			cout << aIPv4[i];
		else
			cout << aIPv4[i] << ".";
	}
}

void IPv4::InterIP(IPv4 ip1)
{
	for (int i = 0; i < MAX_IPV4_SIZE; i++)
	{
		if (this->aIPv4[i] == ip1.aIPv4[i])
		{
			if (i == 3)
			{
				for (int j = ip1.aIPv4[i] + 1; j < this->aIPv4[i]; j++)
				{
					cout << ip1.aIPv4[0] << "." << ip1.aIPv4[1] << "." << ip1.aIPv4[2] << "." << j;
				}
			}
		}
	}
}