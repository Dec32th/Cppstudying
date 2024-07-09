#pragma once
#include<iostream>
#include"ItemType.h"
using namespace std;

template <typename T>
struct NodeType
{
	T data;	///< A data for each node.
	NodeType* next;	///< A node pointer to point succeed node.
};

template<class ItemType>
class SortedType
{
public:
	SortedType();
	~SortedType();
	void MakeEmpty();
	void Add(ItemType item);
	int GetLength() const;
	int Get(ItemType& item);
	void ResetList();
	void GetNextItem(ItemType& item);
	bool operator>(ItemType& item) const;
	bool operator<(ItemType& item) const;
	bool operator!=(ItemType& item) const;
	bool operator==(ItemType& item) const;

private:
	NodeType<ItemType>* pFirst;	//ù ��° ��带 ����Ŵ
	NodeType<ItemType>* pCurrent;		//���� ����Ű�� ��ġ
	int s_Length;						//��� ��
};

