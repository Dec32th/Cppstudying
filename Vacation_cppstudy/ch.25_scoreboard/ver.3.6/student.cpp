#include"Student.h"
#include"BaseOutput.h"
#include<sstream>
#include<iostream>
#include<iomanip>
#include<limits>
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
	//���� �Է��� ���� �ݺ�
	while (1)
	{
		//�ش� �л��� �̸�, ����, ����, ���� ������ �Է¹޴´�.
		cout << "�̸�(�������) ����, ����, ���� ������ �Է��ϼ��� : \n";
		cin >> name >> kor >> eng >> math;

		if (cin.good())
			break;
		//������ �ִٸ� cin ��ü�� �ʱ�ȭ�Ѵ�.
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		//�ȳ� �޽����� ����Ѵ�
		cout << "[�Է��� �߸��Ǿ����ϴ�.] \n";
	}

	//���� ����� ����Ѵ�.
	ave = float(kor + eng + math) / 3.0f;
}

//���� ������ ȭ�鿡 ����Ѵ�.
void Student::Show(BaseOutput& out) const
{
	//���� ��� �ϳ��� ���ڿ��� �����
	stringstream ss;
	ss.precision(2);
	ss << fixed;
	ss << sNo << " " << name << " " << kor << " ";
	ss << eng << " " << math << "-" << ave;

	//7���� ���ڿ��� ���� �迭�� ����� �ʱ�ȭ
	string record[7];
	for (int i = 0; i < 7; ++i)
		ss >> record[i];


	//��� ��ü�� ������
	out.PutRecord(record);
	
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
	while (1)
	{
		//�ش� �л��� �̸�, ������, ��� ���������� �Է¹޴´�
		cout << "�̸�(�������) ����, ����, ����, ��޿��� ������ �Է��ϼ��� : \n";
		cin >> name >> kor >> eng >> math >> hi_eng;
		
		//������ ���ٸ� �ݺ��� ������
		if (cin.good())
			break;

		//������ �ִٸ� cin��ü�� �ʱ�ȭ�Ѵ�
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		//�ȳ� �޽����� ����Ѵ�
		cout << "[�Է��� �߸��Ǿ����ϴ�.] \n";
	}

	//���� ����� ����Ѵ�.
	ave = float(kor + eng + math + hi_eng)/4.0f;
}

void EngStudent::Show(BaseOutput& out) const
{
	//���� ��� �ϳ��� ���ڿ��� �����
	stringstream ss;
	ss.precision(2);
	ss << fixed;
	ss << sNo << " " << name << " " << kor << " ";
	ss << eng << " " << math << hi_eng << " " << ave;

	//7���� ���ڿ��� ���� �迭�� ����� �ʱ�ȭ�Ѵ�
	string record[7];
	for (int i = 0; i < 7; ++i)
		ss >> record[i];

	//��� ��ü�� ������
	out.PutRecord(record);
}