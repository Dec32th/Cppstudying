#include"list.h"

//��ũ�� ����Ʈ�� ������
//fnDelete : ����� �����͸� ������ �� ȣ���� �Լ��� �ּ�
//deletedata : true�� ����� �����͸� �Բ� �����Ѵ�.
List::List(FN_DELETE fnDelete, bool deleteData)
{
	//���ڸ� ����
	this->fnDel = fnDelete;
	this->deleteData = deleteData;

	//create headnode and initialize
	head = new Node;
	head->prev = head;
	head->next = head;
	head->data = 0;
}

//linked list destructor
List::~List()
{
	//��� ��带 �����Ѵ�
	RemoveAll();

	//��� ��带 �����Ѵ�
	delete head;
	head = 0;
}

//����Ʈ�� ��� ��带 �����ϰ� �����͵� �����Ѵ�
void List::RemoveAll()
{
	//��� ����� ���� ������ �����
	//RemoveAll�Լ��� ȣ�� �Ŀ��� List��ü�� �����ϱ� ����
	Node* current = head->next;

	while (current!= head)
	{
		//���� ��带 ���� ���̹Ƿ� ������带 �����ش�
		Node* next = current->next;

		//���� ����� �����͸� �����Ѵ�
		if (deleteData)
		{
			if (fnDel)
				(*fnDel)(current->data);
			else
				delete current->data;
		}

		//���� ��带 �����Ѵ�
		delete current;

		//current�� ���� ��带 ����Ű�� �Ѵ�.
		current = next;
	}

	//��� ��带 �ʱ�ȭ�Ѵ�.
	head->next = head;
	head->prev = head;
}

//ù ��° ��带 ���Ѵ�
//��ȯ�� : ����Ʈ�� ù ��° ���
Node* List::GetTail() const
{
	//��� ����� ���� ��带 ��ȯ
	//��� ���� �ڱ� �ڽŵ� ����!
	return head->prev;
}

//���ο� ��带 �߰�
//node : �� ��� �ڿ� �� ��尡 �߰�
//data : �� ����� ������
void List::InsertNodeAfter(Node* node, void* data)
{
	//���ԵǷ��� ���� ��, �� ��带 ���س����� �ҽ��ڵ��� ������ ����
	Node* before = node;
	Node* after = node->next;

	//�� ��带 ����� �ʱ�ȭ�Ѵ�
	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = after;
	newNode->prev = before;

	//
}