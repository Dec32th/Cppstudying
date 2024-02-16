#pragma once

//linked list ���
#include"list.h"

//���� ������ �����ϴ� Ŭ����
class Students
{
public:

	//ShowAll()���� ��� ������ �����ϱ� ���� ����ü
	enum FORMAT{ CONSOLE, TEXTFILE, HTMLFILE };

	Students();
	~Students();

	bool AddStudent(bool general);
	void ShowAll(FORMAT fmt);

	//�� �Լ��� �ּҸ� List ��ü�� �����ڿ� �Ѱ��ָ� ���� ����Լ��� �Ǿ�߸� ����
	static void DeleteData(void* data);
private:
	List students;				//��ũ�� ����Ʈ
	float TotalAve;				//��ü ���
	int NumberOfStudent;		//������� �Է��� �л� ��
};