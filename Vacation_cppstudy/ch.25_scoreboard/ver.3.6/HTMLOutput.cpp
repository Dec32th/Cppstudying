#include"BaseOutput.h"
#include"HTMLOutput.h"
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

	fout << "<html><head><title>IT ��δ밣 C++ ������Ʈ</title></head></html><center>";
}

void HTMLOutput::BeginTable(STR title)
{
	//Ÿ��Ʋ�� ����Ѵ�
	fout << "<h3>" << title << "</h3>";

	//���̺� ���� �±׸� �ִ´�
	fout <<"<table bgcolor = 'slategray' cellspacing = '1' cellpadding ='4' border = '0'>";
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