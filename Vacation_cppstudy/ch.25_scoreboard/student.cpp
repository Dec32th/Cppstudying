#include"Student.h"
#include<iostream>
#include<iomanip>
using namespace std;

//constructor sNo: studentNumber
Student::Student(int sNo)
{
	//allocate studentNumber
	this->sNo = sNo;

	//������ ��� �ʱ�ȭ
	kor = eng = math = 0;
	ave = 0.0f;
}

Student::~Student()
{
	//����α�
}

//���������� �Է�
void Student::Input()
{
	//�ش� �л��� �̸�, ������ ������ �Է¹޴´�.
	cout << "�̸�(�������) ����, ����, ���� ������ �Է��ϼ��� : \n";
	cin >> name >> kor >> eng >> math;

	//���� ��� ���
	ave = float(kor + eng + math) / 3.0f;
}

//���� ������ ȭ�鿡 ����Ѵ�.
void Student::Show() const
{
	cout << setw(7) << sNo << setw(7) << name;
	cout << setw(5) << kor << setw(5) << eng;
	cout << setw(5) << math << setw(9) << "-";
	cout << setw(7) << ave << endl;
}

//accessors
int Student::GetStdNumber() const
{
	return sNo;
}

string Student::GetName() const
{
	return name;
}

int Student::GetKor() const
{
	return kor;
}

int Student::GetEng() const
{
	return eng;
}

int Student::GetMath() const
{
	return math;
}

float Student::GetAverage() const
{
	return ave;
}

//EngStudent class

//constructor
EngStudent::EngStudent(int sNo)
:Student(sNo)
{
	//EngStudent�� �ִ� ����� �ʱ�ȭ�Ѵ�.
	hi_eng = 0;
}

//������ �Է� �޴´�.
void EngStudent::Input()
{
	//�ش� �л��� �̸�, ����, ����, ����, ��޿��� ������ �Է¹޴´�.
	cout << "�̸�(�������) ����, ����, ����, ��޿��� ������ �Է��ϼ��� : ";
	cin >> name >> kor >> eng >> math >> hi_eng;

	//���� ����� ����Ѵ�.
	ave = float(kor + eng + math + hi_eng)/4.0f;
}

void EngStudent::Show() const
{
	cout << setw(7) << sNo << setw(7) << name;
	cout << setw(5) << kor << setw(5) << eng;
	cout << setw(5) << math << setw(9) << hi_eng;
	cout << setw(7) << ave << endl;
}