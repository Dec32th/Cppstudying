#include"students.h"
#include"student.h"
#include"BaseOutput.h"
#include"ConsoleOutput.h"
#include"HTMLOutput.h"
#include"TextOutput.h"
#include<sstream>
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
	Student* std = NULL;
	try
	{
		//�л��� ������ �´� ��ü�� �����Ѵ�
		if (general)
			std = new Student(NumberOfStudent + 1);
		else
			std = new EngStudent(NumberOfStudent + 1);

		//���� ������ �Է¹޴´�
		std->Input();

		//���� ���� ����ؼ� ���ο� ��ü ����� ���
		const int current = NumberOfStudent + 1;		//������� �Է¹��� �л� ��
		const int prev = NumberOfStudent;				//���� ������ �Է� ���� �л� ��

		TotalAve = (TotalAve * prev / current) + (std->GetAverage() / current);

		//�Է� ���� �л� ���� ������Ų��
		NumberOfStudent++;

		//students ����Ʈ�� �� ��带 �߰��Ѵ�
		students.InsertNodeAfter(students.GetTail(), std);
	}
	catch (...)
	{
		delete std;
		std = NULL;

		throw;
	}
	//if (general)
	//	std = new Student(NumberOfStudent + 1);
	//else
	//	std = new EngStudent(NumberOfStudent + 1);

	////���� ������ �Է� �޴´�.
	//std -> Input();

	////���� ���� ����Ͽ� ���ο� ��ü ����� ����Ѵ�.
	//const int current = NumberOfStudent + 1;
	//const int prev = NumberOfStudent;
	//
	//TotalAve = (TotalAve * prev / current) + (std->GetAverage());

	////�Է� ���� �л� ���� ������Ų��
	//NumberOfStudent++;

	////Students ����Ʈ�� �� ��带 ������Ų��
	//students.InsertNodeAfter(students.GetTail(), std);

	//return true;
}



//��ũ�� ����Ʈ�� ������ ���ſ� �Լ�
//��ũ�� ����Ʈ�� ����� �����͸� ������ �� �� �Լ��� ȣ��
void Students::DeleteData(void* data)
{
	//Student ����ü�� �ٲ㼭 �����Ѵ�.
	delete (Student*)data;
}

void Students::ShowAll(FORMAT fmt)
{
	//���ܸ� ����ؼ� ����Ʈ ������ ���
	// (�ҽ��� �����ϰ� �ϱ� ���ؼ� Ÿ���� ���� ����)
	typedef auto_ptr<BaseOutput> POUT;
	POUT out;

	//��� ���Ŀ� �´� ��ü�� �����Ѵ�.
	if (TEXTFILE == fmt)
		out = (POUT) new TextOutput(DEFAULT_TEXT_FILENAME);
	else if (HTMLFILE == fmt)
		out = (POUT) new HTMLOutput(DEFAULT_TEXT_FILENAME);
	else
		out = (POUT) new ConsoleOutput;

	//����ǥ�� ����� �����Ѵ�
	out->BeginTable("< ��ü ���� ���� >");

	//header �κ� ���
	string header[7] = { "�й�", "�̸�", "����", "����", "����", "��޿���", "���" };
	out->PutHeader(header, 7);

	//����Ʈ�� �ִ� ��� �л��� ������ ����Ѵ�.
	Node* current = students.GetHead()->GetNext();
	while (current != students.GetHead())
	{
		//���� ����� �����͸� �����´�.
		const Student* std = (Student*)current->GetData();

		//���� ���� ������ ����Ѵ�
		//��� ��ü�� ���ڷ� �ѱ��
		std->Show(*out);

		//���� ��带 ����Ų��.
		current = current->GetNext();
	}

	//����ǥ�� ����� ��ģ��
	out->EndTable();

	//��ü ��� ������ �ϳ��� ���ڿ��� �����
	stringstream ss;
		ss.precision(2);
		ss << fixed;
		ss << "��ü ��� = " << TotalAve;

		//��� ��ü�� ���ڿ��� ������
		out->Wrtie(ss.str());

		//��� ��ü�� �����Ѵ�
		delete out;
		out = NULL;

}