#include"docwriter.h"
#include<fstream>
using namespace std;

DocWriter::DocWriter()
{
	//���� �̸��� �ؽ�Ʈ�� default�� �����صд�.
	_fileName = "NoName.txt";
	_content = "There is no content.";
}

DocWriter::DocWriter(const string& fileName, const string& content)
{
	_fileName = fileName;
	_content = content;
}
DocWriter::~DocWriter()
{
}

//���� �̸��� ����
void DocWriter::SetFileName(const string& fileName)
{
	_fileName = fileName;
}

//������ �ؽ�Ʈ ����
void DocWriter::SetContent(const string& content)
{
	_content = content;
}

//���Ͽ� �ؽ�Ʈ ����
void DocWriter::Write()
{
	//������ ����
	ofstream of(_fileName.c_str());
	//������ ����� ����Ѵ�
	of << "# Content #\n\n";
	//�ؽ�Ʈ�� �ִ� �״�� ����
	of << _content;
}