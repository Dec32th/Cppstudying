#include<iostream>
#include"complex.h"
#include"a.h"
using namespace std;
//�۸��� ���� �͵�
namespace Dog
{
	//�۸��� �� ���� ����
	struct Info
	{
		char name[20];
		int age;
	};

	Info dogs[20];		// �۸��� ����Ʈ
	int count;			//��ü �۸��̵��� ��

	void CreataAll();	//��� �۸��� �����Լ�
};

//�߿��� ���� �͵�
namespace Cat
{
	//�߿��� �� ���� ����
	class Info
	{
	public:
		void Meow();
	protected:
		char name[20];
	};

	Info cats[20];		//�߿��� ����Ʈ
	int count;			//��ü �߿��̵��� ��

	void CreateAll();	//��� �߿��� �����Լ�
}

//��ü �۸��̿� �߿����� �� 
int count;


ostream& operator<<(ostream& os, const Complex right)
{
	os << right.Real() << showpos << right.Imaginary() << "i" << noshowpos;
	return os;
}

int main()
{
	//��� �߿��̸� �����Ѵ�
	Cat::CreateAll();

	//�߿��� �迭�� �����Ѵ�
	Cat::cats[0].Meow();

	//��� �۸��̸� �����Ѵ�.
	Dog::CreataAll();

	//�۸����� ������ ���´�.
	int dog_count = Dog::count;
}