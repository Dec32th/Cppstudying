#include"Student.h"
#include"BaseOutput.h"
#include<sstream>
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
	{
		ss >> record[i];


		//��� ��ü�� ������
		out.PutRecord(record);
	}
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