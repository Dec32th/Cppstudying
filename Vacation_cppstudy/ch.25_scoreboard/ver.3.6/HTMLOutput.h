#pragma once
#include"BaseOutput.h"
#include<fstream>
using namespace std;

//�ܼ� ����� �����ִ� Ŭ����
class HTMLOutput : public BaseOutput
{
public:
	HTMLOutput(STR filename);
	virtual ~HTMLOutput();

	virtual void BeginTable(STR title);
	virtual void PutHeader(string headers[], int number);
	virtual void PutRecord(string record[]);
	virtual void EndTable();
	virtual void Write(STR text);

protected:
	int columns;		//����� ����
	ofstream fout;		//������ ������ ��ü	
};