#include<iostream>

using namespace std;

class NeedConstructor
{
public:
	const int maxCount;
	int& ref;
	int sample;

	NeedConstructor();
	NeedConstructor(int count, int& number);
};

NeedConstructor::NeedConstructor(int count, int& number)
	:maxCount(count), ref(number) // const���� reference�� �ִ� ��쿡�� ��� �ʱ�ȭ ����Ʈ�� �ʿ��ϴ�. 
{
	sample = 200;
}

NeedConstructor::NeedConstructor()
	:maxCount(100), ref(sample) //�̷� ���·� ������ �� �ְ�, parameter�� �̿��ؼ� ������ ���� �ִ�.
{
	sample = 200;
}

int main()
{
	//������ ���� ����
	int number = 400;

	//��ü�� ����
	NeedConstructor cr(300, number);

	//������ ���
	cout << "cr.maxCount = " << cr.maxCount << endl;
	cout << "cr.ref = " << cr.ref << endl;

}