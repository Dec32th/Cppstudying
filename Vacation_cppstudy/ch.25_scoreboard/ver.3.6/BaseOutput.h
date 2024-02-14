#pragma once
#include<string>
using namespace std;

// �ҽ� �ڵ带 �����ϰ� �ϱ� ���ؼ� Ÿ�� ���� ����
typedef const string& STR;

// console ����� �����ִ� Ŭ����
class BaseOutput
{
public:
	virtual void BeginTable(STR title) = 0;
	virtual void PutHeader(string headers[], int number) = 0;
	virtual void PutRecord(string record[]) = 0;
	virtual void EndTable() = 0;
	virtual void Wrtie(STR text) = 0;

	virtual ~BaseOutput() {};
};