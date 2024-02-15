#include<iostream>
#include<exception>
#include"students.h"
#include"BaseOutput.h"
#include"menu.h"
#include"list.h"
using namespace std;

int main()
{
	Students s;
	// ���α׷��� ������ ������ �޴��� �����ְ�
	while (1)
	{
		try
		{
			//�޴��� �����ش�
			MENU select;
			select = ShowMenu();

			//���õ� ���� ���� ó��
			switch (select)
			{
				//�޴��� �����ش�
				MENU select;
				select = ShowMenu();

				//���õ� ���� ���� ó��
				switch (select)
				{
				case MENU_ADD_STUDENT:
				case MENU_ADD_STUDENT_ENG:
					//�л� ���� �߰�
					{
						//�л� ���� �߰� �Լ��� ȣ���Ѵ�
						//(�Ϲ��л��̶�� true�� ���ڷ� �ѱ��.)
						bool succeeded;
						succeeded = s.AddStudent((MENU_ADD_STUDENT == select ? true : false));

						//����� �˸���.
						if (succeeded)
							cout << "\n�л� ������ �ùٸ��� �ԷµǾ����ϴ�.\n";
						else
							cout << "\n�� �̻� �Է��� �� �����ϴ�.\n";
						break;
					}
				case MENU_SHOW_ALL:
					//��ü ���� ����
				{
					s.ShowAll(Students::CONSOLE);
					break;
				}
				case MENU_SAVE_TEXT:
					//�ؽ�Ʈ ���Ϸ� ��ü ���� ����
				{
					//��ü ���� ���� �Լ��� ȣ���Ѵ�
					s.ShowAll(Students::TEXTFILE);
					cout << "\n�ؽ�Ʈ ������ ����Ǿ����ϴ�. \n";
					break;
					
				}
				case MENU_SAVE_HTML:
					//html���Ϸ� ��ü ���� ����
				{
					//��ü ���� ���� �Լ��� ȣ���Ѵ�
					s.ShowAll(Students::HTMLFILE);
					
					cout << "\nHTML ������ ����Ǿ����ϴ�. \n";
				}
				case MENU_QUIT:
					//����
				{
					//����� ���ҽ��� ���������� �ʾƵ� �ȴ�.
					//Teardown();
					cout << "\n���α׷��� �����մϴ�\n";
				}

				}
			} 
		} //try�� ��
		catch (exception& e)
		{
			//���� ������ ����ϰ� ��� �����Ѵ�.
			cout << "\n[ ������ ���� ������ �߻��߽��ϴ� ]\n";
			cout << "=> " << e.what() << "\n\n";
		}
	}
	
	//������ ���� ���� ó��
		
}