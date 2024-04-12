#include"DoubleStack.h"
#include<iostream>

using namespace std;

//flag1,2�� ���� Push�� �� ������Ų �Ŀ� �ֱ�
DoubleStack::DoubleStack()
{
	flag1 = -1;
	flag2 = 200;
}

bool DoubleStack::IsEmpty()
{
	return(flag1 == -1 && flag2 == 200);
}

bool DoubleStack::IsFull()
{
	return(flag2 - flag1 == 1);
}

void DoubleStack::Push(int item)
{
	if (IsFull())
		throw EmptyStack();
	else
	{
		if (item > 1000)
		{
			--flag2;
			items[flag2] = item;
		}
		else
		{
			++flag1;
			items[flag1] = item;
		}
	}
}

void DoubleStack::Print()
{
	
	if (IsEmpty())
		cout << "There is Empty stack.";
	else
	{
		while (flag1 > -1)
		{
			cout << items[flag1] << endl;
			flag1--;
		}
		while (flag2 < 200)
		{
			cout << items[flag2] << endl;
			flag2++;
		}
	}
	
}