#include<iostream>
using namespace std;

int DivZero(int a, int b, int c)
{
	int testing = 0;
	if (a < 0 &&b<0 &&c<0)
	{
		testing = 1;
		throw testing;
	}
	else if (a == 0 && b == 0 && c == 00)
	{
		testing = 2;
		throw testing;
	}
	
	return a + b * c + b / c;
}


int main()
{
	try
	{
		cout << DivZero(-4, -1, -1) << endl;
	}
	catch(int ex) //������ ���� ���� ������� �ص� �������. ������ throw�� ������ �� ���� �޾Ƽ� ó���ϱ� ����.
	{
		if (ex == 1)
			cout << "��� ���� 0���� ���� �� �����ϴ�." << endl;

		else if (ex == 2)
			cout << "��� ���� 0�� �� �� �����ϴ�." << endl;

		else
			cout << "ERROR!";
	}

}