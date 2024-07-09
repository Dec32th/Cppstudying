#pragma once
#ifndef _DOUBLYITERATOR_H
#define _DOUBLYITERATOR_H

#include "DoublySortedLinkedList.h"

template<typename T>
struct DoublyNodeType;
template<typename T>
class DoublySortedLinkedList;

/**
*	���Ḯ��Ʈ���� ���̴� Iterator�� Ŭ����.
*/
template <typename T>
class DoublyIterator
{
	friend class DoublySortedLinkedList<T>;
public:
	/**
	*	����Ʈ ������.
	*/
	DoublyIterator(const DoublySortedLinkedList<T>& list) : m_List(list), m_pCurPointer(list.m_pFirst)
	{}; ///< DoublySortedLinkedList�� ģ�� Ŭ����.


	bool NotNull();
	bool NextNotNull();
	ItemType First();
	ItemType Next();
	DoublyNodeType<ItemType> GetCurrentNode();
private:
	const DoublySortedLinkedList<ItemType>& m_List;
	DoublyNodeType<ItemType>* m_pCurPointer;
};

bool DoublyIterator<ItemType>::NotNull()
{
	return m_pCurPointer != NULL;
}

bool DoublyIterator<ItemType>::NextNotNull()
{
	return m_pCurPointer->next != NULL;
}

ItemType DoublyIterator<ItemType>::First()
{
	return m_List.m_pFirst->data.GetId();
}

ItemType DoublyIterator<ItemType>::Next()
{
	m_pCurPointer = m_pCurPointer->next;
	return m_pCurPointer->data;
}

DoublyNodeType<ItemType> DoublyIterator<ItemType>::GetCurrentNode()
{
	return *m_pCurPointer;
}


#endif _DOUBLYITERATOR_H