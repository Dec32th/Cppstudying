#pragma once
#include"ItemType.h"

//exception handling
class FullStack
{};

class EmptyStack
{};

class DoubleStack
{
public:
	DoubleStack();

	bool IsEmpty();
	//����ִ��� �ƴ��� Ȯ��

	bool IsFull();
	// flag1�� flag2�� ���� ���ӵǾ������� IsFull

	void Push(int item);
	//item�� ���� ���� �ִ� ��ġ�� �޶�����.
	//1. IsFull �Ǻ�,
	//2. item�� �� �Ǻ� (1000����, �ʰ�)

	void Print();
private:
	int flag1;
	int flag2;
	int items[MAX_ITEMS];
};