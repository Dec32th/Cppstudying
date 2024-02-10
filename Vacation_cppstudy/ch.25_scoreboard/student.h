#pragma once
#include<string>
using namespace std;

//�� ���� �л��� ���� ������ ����
class Student
{
public:
	Student(int sNo);
	virtual~Student();
	virtual void Input();
	virtual void Show() const;

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

//��� ��� ��� �л��� ���� Ŭ����
//������ ������ Ŭ����
class EngStudent : public Student
{
public:
	EngStudent(int sNo);
	virtual void Input();
	virtual void Show() const;

protected:
	int hi_eng;
};