#pragma once
#include<exception>
using namespace std;

//�� ������Ʈ ����� ����
class MyException : public exception
{
public:
	//������
	//msg : ���ܸ� �����ϴ� ���ڿ�
	MyException(const string& msg)
		:_Str(msg)
	{
	}

	//destructor
	virtual ~MyException()
	{
	}

	//���� ���� ���ڿ��� ��ȯ
	//��ȯ �� : ���ڿ�
	virtual const char *what() const
	{
		return _Str.c_str();
	}

protected:
	string _Str;
};