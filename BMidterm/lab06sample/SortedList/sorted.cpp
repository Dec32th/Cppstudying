#include"sorted.h"

SortedType<ItemType>::SortedType()
{
	pFirst = NULL;
	pCurrent = NULL;
	s_Length = 0;
}

SortedType<ItemType>::~SortedType()
{
	MakeEmpty();
}

template<>
void SortedType<ItemType>::MakeEmpty()
{
	NodeType<ItemType>* tempPtr;
	while (pFirst != NULL)
	{
		tempPtr = pFirst;
		pFirst = pFirst->next;
		delete tempPtr;
	}
	s_Length = 0;
}

int SortedType<ItemType>::GetLength() const
{
	return s_Length;
}

int SortedType<ItemType>::Get(ItemType& item)
{
	NodeType<ItemType>* loc;
	bool bChecker = false;
	loc = pFirst;
	while (bChecker !=true)
	{
		if (item == loc->data)
		{
			bChecker = true;
			item = loc->data;
		}
		else if (loc != NULL)
		{
			loc = loc->next;
		}
		else
			break;
	}
	if (bChecker)
		return 1;
	else
		return 0;
}

void SortedType<ItemType>::Add(ItemType item)
{
	NodeType<ItemType>* loc;
	NodeType<ItemType>* predLoc;
	NodeType<ItemType>* tempPtr;
	tempPtr = new NodeType<ItemType>;
	tempPtr->data = item;

	//�� linked list�� ��� ���� ó���� �߰����ָ� �ȴ�.
	if (pFirst ==NULL)
	{
		pFirst = tempPtr;
		tempPtr->next = NULL;
		s_Length++;
	}

	//������� ���� ��� - �˻縦 ���ؼ� ������� ���� �־���Ѵ�.
	else
	{
		loc = predLoc = pFirst;
		while (loc != NULL)
		{
			if (item < loc->data)
				break;
			else if (item > loc->data)
			{
				predLoc = loc;
				loc = loc->next;
			}
		}
		//��尡 ������� ������, ���� �տ� �־���ϴ� ���
		if (predLoc == loc)
		{
			tempPtr->next = pFirst;
			pFirst = tempPtr;
		}
		//�� �������� �־���ϴ� ���
		else if (predLoc->next==NULL)
		{
			predLoc->next = tempPtr;
			tempPtr->next = NULL;
		}
		//�׿� - �Ϲ������� ���̿� �־���ϴ� ���
		else
		{
			predLoc->next = tempPtr;
			tempPtr->next = loc;
		}
		s_Length++;
	}
}

void SortedType<ItemType>::ResetList()
{
	pCurrent = NULL;
}

//������ item���� �޾Ƽ� ����ϴ� ��
void SortedType<ItemType>::GetNextItem(ItemType& item)
{
	if (pCurrent == NULL)
	{
		pCurrent = pFirst;
	}
	else
	{
		pCurrent = pCurrent->next;
	}
	item = pCurrent->data;
}

bool SortedType<ItemType>::operator>(ItemType& item) const
{
	return this->pCurrent->data > item;
}

bool SortedType<ItemType>::operator<(ItemType& item) const
{
	return this->pCurrent->data < item;
}

bool SortedType<ItemType>::operator==(ItemType& item) const
{
	return this->pCurrent->data == item;
}

bool SortedType<ItemType>::operator!=(ItemType& item) const
{
	return this->pCurrent->data != item;
}