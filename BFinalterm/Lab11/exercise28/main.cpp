#include<iostream>
#include"InsertionSort.h"
#include<string>
using namespace std;

int main()
{
	Student stu;
	stu.InitValue(0, 2003200111, "�̿���", 3.0);
	stu.InitValue(1, 2004200121, "�ǿ���", 3.2);
	stu.InitValue(2, 2005200132, "������", 2.7);

	int StudentCount = stu.GetStudentNum();

	InsertionSort(stu);
	for (int i = 0; i < StudentCount; i++)
	{
		stu.GetStudentInfo(i);
	}
}