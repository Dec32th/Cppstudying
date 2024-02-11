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
bool Students::AddStudent(bool general)
{
	//��ũ�� ����Ʈ�� �ֱ� ���� Student ���� �ϳ��� �������� �Ҵ��Ѵ�.
	Student* std = new Student(NumberOfStudent + 1);
	if (general)
		std = new Student(NumberOfStudent + 1);
	else
		std = new EngStudent(NumberOfStudent + 1);

	//���� ������ �Է� �޴´�.
	std -> Input();

	//���� ���� ����Ͽ� ���ο� ��ü ����� ����Ѵ�.
	const int current = NumberOfStudent + 1;
	const int prev = NumberOfStudent;
	
	TotalAve = (TotalAve * prev / current) + (std->GetAverage());

	//�Է� ���� �л� ���� ������Ų��
	NumberOfStudent++;

	//Students ����Ʈ�� �� ��带 ������Ų��
	students.InsertNodeAfter(students.GetTail(), std);

	return true;
}

//��ü ������ �����ش�
void Students::ShowAll()
{

	//�Ǽ� ��� �ÿ� �Ҽ��� ���� �� �ڸ��� ǥ��
	cout.precision(2);
	cout << fixed;

	//Ÿ��Ʋ �κ��� ���
	cout << "\n			< ��ü ���� ���� >";
	cout << "\n		�й�	�̸�	���� ���� ����	���\n";

	//����Ʈ�� �ִ� ��� �л��� ������ ����Ѵ�
	Node* current = students.GetHead()->GetNext();
	while (current != students.GetHead())
	{
		//���� ����� �����͸� �����´�
		const Student* std = (Student*)current->GetData();

		//���� ����ǥ�� ����Ѵ�
		std->Show();

		//���� ��带 ����Ŵ
		current = current->GetNext();

	}

	//��ü ����� ����Ѵ�
	cout << "\n��ü ��� = " << TotalAve << endl;

}

//��ũ�� ����Ʈ�� ������ ���ſ� �Լ�
//��ũ�� ����Ʈ�� ����� �����͸� ������ �� �� �Լ��� ȣ��
void Students::DeleteData(void* data)
{
	//Student ����ü�� �ٲ㼭 �����Ѵ�.
	delete (Student*)data;
}

