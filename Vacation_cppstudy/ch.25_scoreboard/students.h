#pragma once

//linked list ���
#include"List.h"

//���� ������ �����ϴ� Ŭ����
class Students
{
public:
	Students();
	~Students();

	bool AddStudent();
	void ShowAll();

	//�� �Լ��� �ּҸ� List ��ü�� �����ڿ� �Ѱ��ָ� ���� ����Լ��� �Ǿ�߸� ����
	static void DeleteData(void* data);
private:
	List students;				//��ũ�� ����Ʈ
	float TotalAve;				//��ü ���
	int NumberOfStudent;		//������� �Է��� �л� ��
};