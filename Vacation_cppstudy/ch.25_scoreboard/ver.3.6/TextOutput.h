#pragma once

#include"ConsoleOutput.h"
#include<fstream>
using namespace std;

//�ؽ�Ʈ���� ����� �����ִ� �Լ�
class TextOutput : public ConsoleOutput
{
public:
	TextOutput(STR filename);
	virtual ~TextOutput();

	//BaseOutput�� ��� �Լ����� ���� �������̵��� �ʿ�� ����

protected:
	virtual ostream& StdOut();
	ofstream fout;
};