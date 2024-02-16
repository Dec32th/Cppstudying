#pragma once

// �ϳ��� �����͸� ������ Ŭ����
class Node
{
	//list Ŭ�������� ��� ����� ���� �����ϵ���
	friend class List;

public:
	Node* GetNext() const;
	Node* GetPrev() const;
	void* GetData() const;

private:
	Node* prev;			//���� Node ����ü
	Node* next;			//���� Node ����ü
	void* data;			//�����Ϳ� ���� ������
};

//��ü ����Ʈ�� �����ϴ� Ŭ����
class List
{
public:
	//������ ���Ÿ� ���� �Լ��� ������
	typedef void(*FN_DELETE)(void*);

	List(FN_DELETE fnDelet = 0, bool deleteData = true);
	~List();

	void InsertNodeAfter(Node* node, void* data);
	void RemoveNode(Node* node);
	Node* GetHead() const;
	Node* GetTail() const;

	void RemoveAll();

private:
	Node* head;			//���(����) ���
	bool deleteData;	//����Ʈ, ��� ���� �� ������ ���� ����
	FN_DELETE fnDel;	//������ ���� �� ȣ���� �Լ�
};