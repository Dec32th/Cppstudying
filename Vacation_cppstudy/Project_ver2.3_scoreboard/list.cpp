#include<iostream>
#include"student.h"
#include"list.h"


using namespace std;

struct Node
{
	//�յڷ� ����� ��带 ����Ű�� ������
	Node* prev;
	Node* next;

	//Ÿ�԰� ������� ����Ų��.
	void* data;
};

struct List
{
	Node* head;
};

List* CreateList()
{
	//��� ��带 ����� �ʱ�ȭ�Ѵ�.
	Node* head = new Node;
	head->prev = head;
	head->next = head;
	head->data = 0;

	//List ����ü�� ����� �ʱ�ȭ�Ѵ�
	List* list = new List;
	list->head = head;

	//List����ü�� ��ȯ
	return list;
}

//���ο� ��带 �߰��Ѵ�.
//node: �� ��� �ڿ� �� ��尡 �߰��ȴ�.
//data: �� ����� ������
void InsertNodeAfter(Node* node, void* data)
{
	//���ԵǷ��� ���� ��, �� ��带 ���س����� �б� ���� �ҽ��ڵ带 ���� �� �ִ�.
	Node* before = node;
	Node* after = node->next;

	//�� ��带 ����� �ʱ�ȭ
	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = after;
	newNode->prev = before;

	//node�� �ڿ� �ִ� ��尡 �� ��带 ����Ű���� ��
	after->prev = newNode;

	//�Ű� ���� node�� �� ��带 ����Ű�� ��
	before->next = newNode;
}

//��带 �����Ѵ�.
//node: ������ ���
//deleteData: treu�̸� ��尡 ����Ű�� �����͵� �����Ѵ�.
void RemoveNode(Node* node, bool deleteData)
{
	//node�� ��, �ڸ� ���ϸ� �б� ���� �ڵ带 ���� �� �ִ�.
	Node* before = node->prev;
	Node* after = node->next;

	//node�� ���� ���� ���� ��带 �������ش�.
	before->next = after;
	after->prev = before;

	//node�����Ϳ� node �ڽ��� �����Ѵ�
	if (deleteData)
		delete node->data;
	delete node;

}

void ShowNames(List* students)
{
	//��� ����� ���� ������ ����
	Node* current = students->head->next;

	while (current!=students->head)
	{
		//���� ����� �����͸� �����´�
		const Student* std = (Student*)current->data;
		
		//�ش� �л��� �̸��� ����Ѵ�.
		cout << std->name << endl;

		//���� ��带 ����Ų��
		current = current->next;
	}
}

//����Ʈ�� �����Ѵ�
//����Ʈ�� ��� ���� �����͵� �����Ѵ�.
//list : ����Ʈ
//deleteData : true �� ����� �����͵� �����Ѵ�.
void RemoveList(List* list, bool deleteData)
{
	//head ������ ������ ������ �����Ѵ�.
	Node* current = list->head;

	do
	{
		//���� ��带 ������ ���̹Ƿ� ������� ����
		Node* current = list->head;
		
		//���� ���� ����� �����͸� �����Ѵ�.
		if (deleteData)
			delete current->data;
		delete current;

		//���� ��带 �����Ѵ�.
		current = next;
	}
	while (current!= list->head)
	
		//while���� �����ؼ� list->head�� ����Ű�� �޸𸮴� �����Ǿ����� �ּҴ� ����� �� �ִ�.
		//rmrhtdml fltmxm wprj
		delete list;
}