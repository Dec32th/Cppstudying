#pragma once
#include<iostream>
#include"SumSquare.hpp"

template<typename T>
struct NodeType
{
    T info;	///< A data for each node.
    NodeType* next;	///< A node pointer to point succeed node.
};

template <typename T>
class UnsortedType
{
public:
	/**
	*	default constructor.
	*/
	UnsortedType();

	/**
	*	destructor.
	*/
	~UnsortedType();

	/**
	*	@brief	Initialize list to empty state.
	*	@pre	None
	*	@post	List is empty.
	*/
	void MakeEmpty();

	/**
	*	@brief	Get number of elements in the list.
	*	@pre	None.
	*	@post	Function value = number of elements in list.
	*	@return	Number of elements in this list.
	*/
	int GetLength() const;

	/**
	*	@brief	Add item into this list.
	*	@pre	List is not full. item is not in list.
	*	@post	Item is inserted in this list.
	*	@return	1 if this function works well, otherwise 0.
	*/
	int Add(T item);

	/**
	*	@brief	Retrieve list element whose key matches item's key (if present).
	*	@pre	Key member of item is initialized.
	*	@post	If there is an element whose key matches with item's key then the element's record is copied to the item.
	*	@return	1 if any element's primary key matches with item's, otherwise 0.
	*/
	int Get(T& item);

	/**
	*	@brief	Initialize current pointer for an iteration through the list.
	*	@pre	None.
	*	@post	current pointer is prior to list. current pointer has been initialized.
	*/
	void ResetList();

	/**
	*	@brief	Get the next element in list.
	*	@pre	current pointer is defined. Element at current pointer is not last in list.
	*	@post	current pointer is updated to next position. item is a copy of element at current pointer.
	*/
	void GetNextItem(T& item);
	void UnsortedType<ItemType>::PrintSumSquares();

private:
	NodeType<T>* listPtr;	///< Pointer for pointing a first node.
	NodeType<T>* m_pCurPointer;	///< Node pointer for pointing current node to use iteration.
	int m_nLength;	///< Number of node in the list.
};

// Class constructor
template <typename T>
UnsortedType<T>::UnsortedType()
{
	m_nLength = 0;
	listPtr = NULL;
	m_pCurPointer = NULL;
}


// Class destructor
template <typename T>
UnsortedType<T>::~UnsortedType()
{
	//����Ʈ���� ��� node ����
	MakeEmpty();
}


// Initialize list to empty state.
template <typename T>
void UnsortedType<T>::MakeEmpty()
// Post: List is empty; all items have been deallocated.
{
	// ����Ʈ���� ��� ��� ���� �ϰ� ����Ʈ�� length�� �ʱ�ȭ
	NodeType<T>* tempPtr;

	while (listPtr != NULL)
	{
		tempPtr = listPtr;
		listPtr = listPtr->next;
		delete tempPtr;
	}

	m_nLength = 0;
}


// Get number of elements in the list.
template <typename T>
int UnsortedType<T>::GetLength() const
{
	return m_nLength;
}


// Add item into this list.
template <typename T>
int UnsortedType<T>::Add(T item)
{
	// ����Ʈ �ʱ�ȭ
	ResetList();

	// ����Ʈ�� �߰��� ���ο� node ��ü�� ���� ��带 ����ų ������ ����
	NodeType<T>* node = new NodeType<T>;
	NodeType<T>* pre;
	T dummy;
	bool bFound = false;

	// node ��ü�� �Է¹��� ������ ���� �� �ʱ�ȭ
	node->data = item;
	node->next = NULL;

	// list �� node �� �������� �ʴ� ���
	if (!m_nLength)
	{
		listPtr = node;
	}
	// list �� node �� �ϳ� �̻� �����ϴ� ���
	else
	{
		// ���� ������ node �� �̵� �� ����
		while (1)
		{
			// ���� ��带 ����Ű�� ������ ����
			pre = m_pCurPointer;

			// iteration �� �̿��� node ������ ����.
			GetNextItem(dummy);

			// node �����Ͱ� ������ node �� ����Ű�� �� �ڿ� ���ο� node ����.
			if (m_pCurPointer->next == NULL)
			{
				// ������ node �� ���ο� node ����
				m_pCurPointer->next = node;
				break;
			}
		}
	}

	m_nLength++;

	return 1;
}


// Retrieve list element whose key matches item's key (if present).
template <typename T>
int UnsortedType<T>::Get(T& item)
{
	bool moreToSearch, found;
	NodeType<T>* location;

	location = listPtr;
	found = false;
	moreToSearch = (location != NULL);

	while (moreToSearch && !found)
	{
		if (item == location->data)
		{
			found = true;
			item = location->data;
		}
		else
		{
			location = location->next;
			moreToSearch = (location != NULL);
		}
	}

	if (found)
		return 1;
	else
		return 0;
}


// Initializes current pointer for an iteration through the list.
template <typename T>
void UnsortedType<T>::ResetList()
{
	// current pointer �ʱ�ȭ
	m_pCurPointer = NULL;
}


// Gets the next element in list.
template <typename T>
void UnsortedType<T>::GetNextItem(T& item)
{
	// current pointer �� NULL�̶�� ó�� node�� ����Ŵ.
	if (m_pCurPointer == NULL)
	{
		m_pCurPointer = m_pList;
	}
	else
		//current position �� ���� ���� �̵�
		m_pCurPointer = m_pCurPointer->next;

	//item �� current position �� info �� ����
	item = m_pCurPointer->data;
}


//����Լ� �ۼ� �ʿ�. ���� �����ؼ� ���Ѵ�.
//����Ʈ�� ������� �ʴٰ� �����Ѵ�.
//����ִ� ����Ʈ�� �������� ������ ���� �۵��� �� �־���Ѵ�.
template <class ItemType>
ItemType SumSquares(NodeType<ItemType>* list)
{
	ItemType iTotal;
	if (list == NULL)
		return 0;
	else if ((list->next) == NULL)
		return iTotal = (list->info) * (list->info);
	else
		return iTotal += SumSquares(list->next);

}

//return 0�� �տ� �����ϱ� ������ return�� �ϰ� �ٷ� �Լ��� ����Ǿ� �Ʒ��� ����� ���� �ʰԵȴ�.
template<class ItemType>
ItemType SumSqures_a(NodeType<ItemType>* list)
{

	if (list != NULL)
		return (list->info * list->info) + SumSqures(list->next);
	else
		return 0;
}

// ������ �ƴ϶� �׳� ���� ���� ���� �����̴�.
template<class ItemType>
ItemType SumSquares_b(NodeType<ItemType>* list)
{
	int sum = 0;
	while (list != NULL)
	{
		sum = (list->info*list->info)+ sum; 
		list = list->next;
	}
}


//next�� �̿��ؼ� ���� �ʾҴ�.
template<class ItemType>
ItemType SumSquares_c(NodeType<ItemType>* list)
{
	if (list->next== NULL)
		return 0;
	else
		return list->info * list->info + SumSquares(list->next);
}

//���� list�� NULL�� ��츦 ������� �ʾҴ�!
template<class ItemType>
ItemType SumSquares_d(NodeType<ItemType>* list)
{
	if (list->next == NULL)
		return list->info * list->info;
	else if (list == NULL)
		return 0;
	else
		return list->info * list->info + SumSquares(list->next);
}

////������ �������� ��Ȯ�� �𸣰ڴ�
//template<class ItemType>
//ItemType SumSquares_e(NodeType<ItemType>* list)
//{
//	if (list == NULL)
//		return 0;
//	else
//		return (SumSquares(list->next) * SumSquares(list->next));
//}

template<class ItemType>
void UnsortedType<ItemType>::PrintSumSquares()
{
    //a, b, c, d, e�� ������ ���� �� ���
    cout << SumSquares_a(listData) << endl;  //  a �� �Լ�
    cout << SumSquares_b(listData) << endl;  //  b �� �Լ�
    cout << SumSquares_c(listData) << endl;  //  c �� �Լ�
    cout << SumSquares_d(listData) << endl;  //  d �� �Լ�
    cout << SumSquares_e(listData) << endl;  //  e �� �Լ�
};


