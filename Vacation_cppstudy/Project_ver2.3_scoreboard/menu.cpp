#include"menu.h"
#include<iostream>
using namespace std;

MENU ShowMenu()
{
	while (true)
	{
		cout << "\n------ �޴� ------\n";
		cout << "1. �л� ���� �߰�" << endl;
		cout << "2. ��ü ���� ����" << endl;
		cout << "Q. ���α׷� ����" << endl;
		cout << "--------------------\n\n";
		cout << "���ϴ� �۾��� ��ȣ�� �Է��ϼ��� : ";

		//���� �ޱ�
		char select;
		cin >> select;

		switch (select)
		{
		case '1':
			return MENU_ADD_STUDENT;
		case '2':
			return MENU_SHOW_ALL;
		case 'q':
		case 'Q':
			return MENU_QUIT;
		default:
			//�׿� ����
			cout << "\n�ùٸ� ���� �Է����ּ���.\n";
			break;
		}
	}

	//�� ������ ����� �������� �ʴ´�.
	return MENU_QUIT;
}