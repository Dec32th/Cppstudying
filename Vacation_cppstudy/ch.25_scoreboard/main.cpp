#include<iostream>
#include"student.h"
#include"students.h"
#include"menu.h"
using namespace std;

int main()
{
	// ���α׷��� ������ ������ �޴��� �����ְ�
	while (1)
	{
		//�޴��� �����ش�
		MENU select;
		select = ShowMenu();

		//������ ���� ���� ó��
		switch (select)
		{
		case MENU_ADD_STUDENT:
		case MENU_ADD_STUDENT_ENG:
		//�л� ���� �߰�
		{
			// �Ϲ� �л��̶�� true�� ���ڷ� �ѱ��
			bool succeeded;
			succeeded = s.AddStudent((MENU_ADD_STUDENT==select ? true : false));

			//����� �˸���
			if (succeeded)
				cout << "\n�л� ������ �ùٸ��� �ԷµǾ����ϴ�.\n";
			else
				cout << "\n���̻� �Է��� �� �����ϴ�.\n";
			break;
		}
		case MENU_SHOW_ALL:
			//��ü ���� ����
		{
			//��ü ���� ���� �Լ��� ȣ���Ѵ�
			ShowAll();

			break;
		}
		case MENU_QUIT:
			//����
			cout << "\n���α׷��� �����մϴ�." << endl;
		}
	}
	
	//������ ���� ���� ó��
		
}