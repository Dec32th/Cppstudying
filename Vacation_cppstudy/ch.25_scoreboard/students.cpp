#include"students.h"
#include"student.h"
#include<iostream>
using namespace std;

//constructor
//+call list constructor
Students::Students()
	:students(&Students::DeleteData)
{
	//initialize
	TotalAve = 0.0f;
	NumberOfStudent = 0;
}

//destructor
Students::~Students()
{

}

//�л� �� �� �߰�
//�� �̻� �Է� �Ұ����� ��� false ��ȯ
bool Student::AddStudent()
{
	//��ũ�� ����Ʈ�� �ֱ� ���� Student ���� �ϳ��� �������� �Ҵ��Ѵ�.
	Student* std = new Student(NumberOfStudent + 1);

	//���� ������ �Է� �޴´�.
	std = > Input();
}