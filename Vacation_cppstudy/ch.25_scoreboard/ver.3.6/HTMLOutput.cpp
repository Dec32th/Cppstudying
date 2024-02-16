#include"HTMLOutput.h"
#include"MyException.h"
#include<iostream>
#include<iomanip>
using namespace std;

//������
//filename : HTML ���� �̸�
HTMLOutput::HTMLOutput(STR filename)
{
	columns = 0;
	
	//������ ���� �⺻ �±׸� �߰��Ѵ�
	fout.open(filename.c_str());
	if (false == fout.is_open())
		throw MyException(filename + "�� �� �� �����ϴ�.");

	fout << "<html><head><title>IT ��δ밣 C++ ������Ʈ</title></head></html><center>";
}
//�Ҹ���
HTMLOutput::~HTMLOutput()
{
	//������ �±׸� �ְ� ������ �ݴ´�
	fout << "</center></body></html>";
	fout.close();
}

//ǥ�� ����ϱ� �����Ѵ�
//title : ǥ�� ����
void HTMLOutput::BeginTable(STR title)
{
	//Ÿ��Ʋ�� ����Ѵ�
	fout << "<h3>" << title << "</h3>";

	//���̺� ���� �±׸� �ִ´�
	fout <<"<table bgcolor = 'slategray' cellspacing = '1' cellpadding ='4' border = '0'>";
}

//ǥ�� ����� ����Ѵ�
//headers:�����
//numbers : ����� ����
void HTMLOutput::PutHeader(string headers[], int number)\
{
	//����� ������ �����Ѵ�.
	columns = number;

	//�±׿� �Բ� ����� �����Ѵ�.
	fout << "<TR bgcolor = '#e0e0ff' align = 'center'>";
	for (int i = 0; i < number; ++i)
		fout << "<TD>" << headers[i] << "</TD>";
	fout << "</TR>";
}

//ǥ�� ���ڵ带 ����Ѵ�
//record : ���ڵ�. �� ����� �����͸� �ǹ��Ѵ�
void HTMLOutput::PutRecord(string record[])
{
	//�±׿� �Բ� ���ڵ带 �����Ѵ�
	//���ڵ带 ����Ѵ�
	fout << "<TR bgcolor = 'white' align = 'right'>";
	for (int i = 0; i < columns; ++i)
		fout << "<TD>" << record[i] << "</TD>";
	fout << "</TR>";
}

//ǥ �׸��⸦ ��ģ��
void HTMLOutput::EndTable()
{
	//���̺� ���� �±׸� �ִ´�
	fout << "</table>";
}

//ȭ�鿡 ���ڿ��� ����Ѵ�
//text: ���ڿ�
void HTMLOutput::Write(STR text)
{
	//���ڿ��� ���
	fout << "<p>" << text << "</p>";
}