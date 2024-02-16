#include<iostream>
#include"BaseOutput.h"
#include"ConsoleOutput.h"
#include<string>
#include<iomanip>



// ǥ�� ����� ����Ѵ�
// headers: �����
// numbers: ����� ����
void ConsoleOutput::PutHeader(string headers[], int number)
{
	//����� ������ �����Ѵ�
	columns = number;

	//����� �׷��ش�.
	for (int i = 0; i < number; ++i)
		cout << setw(9) << headers[i];
	
	cout << endl;
}

//ǥ�� ���ڵ带 ����Ѵ�
//record : ���ڵ�. �ѻ���� �����͸� �ǹ��Ѵ�
void ConsoleOutput::PutRecord(string record[])
{
	//���ڵ带 ����Ѵ�
	for (int i = 0; i < columns; ++i)
		cout << setw(9) << record[i];

	cout << endl;
}

void ConsoleOutput::EndTable()
{
	//�ϴ� �� ����. �׳� �� ĭ ����ش�
	StdOut() << "\n";
}

void ConsoleOutput::Write(STR text)
{
	StdOut() << text << "\n";
}

ostream& ConsoleOutput::StdOut()
{
	return cout;
}

ConsoleOutput::ConsoleOutput()
{
	columns = 0;
}

ConsoleOutput::~ConsoleOutput()
{

}

void ConsoleOutput::BeginTable(STR title)
{
	//������ ����Ѵ�
	StdOut() << "\t\t\t\t" << title << "\n";
}