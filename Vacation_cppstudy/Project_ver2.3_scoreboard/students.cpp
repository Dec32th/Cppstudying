#include"student.h"
#include"list.h"
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

//�л��� ������ ������ ����ü
struct Student
{
	int sNo;
	string name;
	int kor, eng, math;
	float ave;
};

//�迭 ��ſ� linked - list�� �̿�
List* students = NULL;

//��ü ��հ� ���� �Էµ� �л� ��
float TotalAve = 0.0f;
int NumberOfStudent = 0;

//�л��� �� �� �߰��Ѵ�.
bool AddStudent()
{
	//linkedlist�� �ֱ� ���ؼ� ������ �������� �ϳ� �Ҵ�.
	Student* std = new Student;
	//�ش� �л��� �л���ȣ�� �ڵ����� �Է��Ѵ�.
	std->sNo = NumberOfStudent + 1;

	//�ش� �л��� �̸�, ������ ������ �Է¹޴´�.
	cout << "�̸�(�������) ����, ����, ���� ������ �Է��ϼ��� : \n";
	cin >> std->name >> std->kor >> std->eng >> std->math;

	//���� ����� ����Ѵ�.
	std->ave = float(std->kor + std->eng + std->math) / 3.0f;

	//���� ���� ����ؼ� ���ο� ��ü ����� ����Ѵ�.
	const int current = NumberOfStudent + 1; //������� �Է¹��� �л� ��
	const int prev = NumberOfStudent; //���� ������ �Է¹��� �л� �� 

	TotalAve = (TotalAve * prev / current) + (std->ave / current);

	//�Է¹��� �л� ���� ������Ų��.
	NumberOfStudent++;

	//students����Ʈ�� �� ��带 �߰�
	InsertNodeAfter(GetTail(students), std);
	return true;
}

//��ü ������ �����ִ� �Լ�
void ShowAll()
{
	//�Ǽ� ��� �ÿ� �Ҽ��� ���� 2�ڸ����� ǥ��
	cout.precision(2);
	cout << fixed;

	//Ÿ��Ʋ ���
	cout << "\n               <��ü ���� ����>";
	cout << "\n   �й�    �̸�    ����    ����    ����    ���\n";

	//����Ʈ�� �ִ� ��� �л����� ������ ����Ѵ�.
	Node* current = students->head->next;
	while (current != students->head)
	{
		//���� ����� �����͸� �����´�
		const Student* std = (Student*)GetData(current);

		//�ش� �л��� ������ ����Ѵ�.
		cout << setw(7) << std->sNo << setw(7) << std->name;
		cout << setw(5) << std->kor << setw(5) << std->eng;
		cout << setw(5) << std->math << setw(7) << std->ave << endl;
		
		//���� ��带 ����Ų��.
		current = GetNext(current);
	}
	

	//��ü ����� ���
	cout << "\n��ü ��� = " << TotalAve << endl;
}

//�ʱ�ȭ
void Setup()
{
	//����Ʈ�� �����Ѵ�
	students = CreateList();
}

//����� ���ҽ��� ����
void Teardown()
{
	//����Ʈ�� ����
	RemoveList(stuents, true)
}