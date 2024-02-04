#include<iostream>
#include"Rect.h"
using namespace std;

int main()
{
	//Rect ��ü ����
	Rect rcl;
	Rect rc2(Point(10, 20), Point(30, 40));
	Rect rc3(50,60,70,80);

	//���� ���
	rcl.Print();
	rc2.Print();
	rc3.Print();

	//���� �ٲ㺻��
	rcl.SetRect(10, 20, 30, 40);

	//���� ���
	rcl.Print();

	//���� �ٲ۴�
	rcl.SetTopLeft(Point(20, 20));

	//���� ���
	rcl.Print();

	//����, ���� ���
	cout << "rcl.Getwidth() = " << rcl.GetWidth() << endl;
	cout << "rcl.GetHeight() = " << rcl.GetHeight() << endl;

}