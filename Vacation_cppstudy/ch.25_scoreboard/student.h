#pragma once
#include<string>
using namespace std;

//�� ���� �л��� ���� ������ ����
class Student
{
public:
	Student(int sNo);
	void Input();
	void Show() const;

	//accessor
	int GetStdNumber() const;
	string GetName() const;
	int GetKor() const;
	int GetEng() const;
	int GetMath() const;
	float GetAverage() const;

protected:
	int sNo;
	string name;
	int kor, eng, math;
	float ave;
};