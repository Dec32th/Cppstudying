#include<iostream>
#include<array>
#include<string>
using namespace std;

//�� �ڸ��� 0-255������ ���ڸ����� �Ǿ�������, .���� ������
//0-255�� �Ǿ��ְ�, 1.0.0.1 ���� 255.255.255.255���� �����ϴ�. -> �Է��� string���� �޾Ƽ� ¥����!!!

const int MAX_IPV4_SIZE = 15;

class IPv4
{
public:
	//�Է� ���� string�� �迭�� �ִ� �Լ� -> �̶�, .�� �������� ������ �־��Ѵ�. 
	int makeIPArray(string IpNum);
	
private:
	string IpNum;
	int aIPv4[MAX_IPV4_SIZE];
	int ipv4Size;
};



// �ϴ� �Է� ���� ���ڸ� .�� �������� �߶���Ѵ�. ��ġ�� �� ���� �迭�� �ִ� �� �ʿ���. 
int IPv4::makeIPArray(string ipNum)
{
	
}