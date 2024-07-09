#pragma once
//singlylinkedlist - unsorted
//#include <iostream>
//using namespace std;
//
//class Node {
//public:
//    int data;
//    Node* next;
//
//    Node(int data) : data(data), next(nullptr) {}
//};
//
//class UnsortedSinglyLinkedList {
//private:
//    Node* head;
//
//public:
//    UnsortedSinglyLinkedList() : head(nullptr) {}
//
//    void insert(int data) {
//        Node* newNode = new Node(data);
//        newNode->next = head;
//        head = newNode;
//    }
//
//    void makeEmpty() {
//        Node* current = head;
//        while (current) {
//            Node* next = current->next;
//            delete current;
//            current = next;
//        }
//        head = nullptr;
//    }
//
//    Node* find(int data) {
//        Node* current = head;
//        while (current && current->data != data) {
//            current = current->next;
//        }
//        return current;
//    }
//
//    void remove(int data) {
//        Node* current = head;
//        Node* previous = nullptr;
//        while (current && current->data != data) {
//            previous = current;
//            current = current->next;
//        }
//        if (current == nullptr) return;
//        if (previous == nullptr) {
//            head = head->next;
//        }
//        else {
//            previous->next = current->next;
//        }
//        delete current;
//    }
//
//    void printList() {
//        Node* current = head;
//        while (current) {
//            cout << current->data << " -> ";
//            current = current->next;
//        }
//        cout << "NULL\n";
//    }
//
//    ~UnsortedSinglyLinkedList() {
//        makeEmpty();
//    }
//};




//singlylinked - sorted
// 
//#include <iostream>
//using namespace std;
//
//class Node {
//public:
//    int data; // ��尡 ������ ������
//    Node* next; // ���� ��带 ����Ű�� ������
//
//    Node(int data) : data(data), next(nullptr) {}
//};
//
//class SortedSinglyLinkedList {
//private:
//    Node* head; // ����Ʈ�� ù ��° ��带 ����Ű�� ������
//
//public:
//    SortedSinglyLinkedList() : head(nullptr) {}
//
//    void insert(int data) {
//        Node* newNode = new Node(data);
//        if (!head || data < head->data) {
//            newNode->next = head;
//            head = newNode;
//        }
//        else {
//            Node* current = head;
//            while (current->next && current->next->data < data) {
//                current = current->next;
//            }
//            newNode->next = current->next;
//            current->next = newNode;
//        }
//    }
//
//    void makeEmpty() {
//        Node* current = head;
//        while (current) {
//            Node* next = current->next;
//            delete current;
//            current = next;
//        }
//        head = nullptr;
//    }
//
//    Node* find(int data) {
//        Node* current = head;
//        while (current && current->data != data) {
//            current = current->next;
//        }
//        return current; // ��ȯ�� �����͸� ���� ã�� ��忡 �����ϰų� nullptr �˻� ����
//    }
//
//    void remove(int data) {
//        Node* current = head;
//        Node* previous = nullptr;
//        while (current && current->data != data) {
//            previous = current;
//            current = current->next;
//        }
//        if (current == nullptr) return; // �����͸� ã�� ���� ���
//        if (previous == nullptr) {
//            head = head->next; // ������ ��尡 ����� ���
//        }
//        else {
//            previous->next = current->next; // �߰� ��峪 ������ ��� ����
//        }
//        delete current;
//    }
//
//    void printList() {
//        Node* current = head;
//        while (current) {
//            cout << current->data << " -> ";
//            current = current->next;
//        }
//        cout << "NULL\n";
//    }
//
//    ~SortedSinglyLinkedList() {
//        makeEmpty();
//    }
//};
//
//int main() {
//    SortedSinglyLinkedList list;
//    list.insert(30);
//    list.insert(20);
//    list.insert(40);
//    list.insert(10);
//    list.printList(); // ���: 10 -> 20 -> 30 -> 40 -> NULL
//    list.remove(20);
//    list.printList(); // ���: 10 -> 30 -> 40 -> NULL
//    list.makeEmpty();
//    list.printList(); // ���: NULL
//    return 0;
//}



//doubly - unsorted

//#include <iostream>
//using namespace std;
//
//class DNode {
//public:
//    int data;
//    DNode* prev;
//    DNode* next;
//
//    DNode(int data) : data(data), prev(nullptr), next(nullptr) {}
//};
//
//class UnsortedDoublyLinkedList {
//private:
//    DNode* head;
//
//public:
//    UnsortedDoublyLinkedList() : head(nullptr) {}
//
//    void insert(int data) {
//        DNode* newNode = new DNode(data);
//        newNode->next = head;
//        if (head) {
//            head->prev = newNode;
//        }
//        head = newNode;
//    }
//
//    void makeEmpty() {
//        DNode* current = head;
//        while (current) {
//            DNode* next = current->next;
//            delete current;
//            current = next;
//        }
//        head = nullptr;
//    }
//
//    DNode* find(int data) {
//        DNode* current = head;
//        while (current && current->data != data) {
//            current = current->next;
//        }
//        return current;
//    }
//
//    void remove(int data) {
//        DNode* current = find(data);
//        if (!current) return;
//
//        if (current->prev) {
//            current->prev->next = current->next;
//        }
//        else {
//            head = current->next;
//        }
//
//        if (current->next) {
//            current->next->prev = current->prev;
//        }
//
//        delete current;
//    }
//
//    void printList() {
//        DNode* current = head;
//        while (current) {
//            cout << current->data << " <-> ";
//            current = current->next;
//        }
//        cout << "NULL\n";
//    }
//
//    ~UnsortedDoublyLinkedList() {
//        makeEmpty();
//    }
//};




//doubly - sorted
//#include <iostream>
//using namespace std;
//
//class DNode {
//public:
//    int data;
//    DNode* prev;
//    DNode* next;
//
//    DNode(int data) : data(data), prev(nullptr), next(nullptr) {}
//};
//
//class SortedDoublyLinkedList {
//private:
//    DNode* head;
//
//public:
//    SortedDoublyLinkedList() : head(nullptr) {}
//
//    void insert(int data) {
//        DNode* newNode = new DNode(data);
//        if (!head || data < head->data) {
//            newNode->next = head;
//            if (head) {
//                head->prev = newNode;
//            }
//            head = newNode;
//        }
//        else {
//            DNode* current = head;
//            while (current->next && current->next->data < data) {
//                current = current->next;
//            }
//            newNode->next = current->next;
//            if (current->next) {
//                current->next->prev = newNode;
//            }
//            newNode->prev = current;
//            current->next = newNode;
//        }
//    }
//
//    void makeEmpty() {
//        DNode* current = head;
//        while (current) {
//            DNode* next = current->next;
//            delete current;
//            current = next;
//        }
//        head = nullptr;
//    }
//
//    DNode* find(int data) {
//        DNode* current = head;
//        while (current && current->data != data) {
//            current = current->next;
//        }
//        return current; // ��ȯ�� �����͸� ���� ã�� ��忡 �����ϰų� nullptr �˻� ����
//    }
//
//    void remove(int data) {
//        DNode* current = find(data);
//        if (!current) return; // �����͸� ã�� ���� ���
//
//        if (current->prev) {
//            current->prev->next = current->next;
//        }
//        else {
//            head = current->next; // ������ ��尡 ����� ���
//        }
//
//        if (current->next) {
//            current->next->prev = current->prev;
//        }
//
//        delete current;
//    }
//
//    void printList() {
//        DNode* current = head;
//        while (current) {
//            cout << current->data << " <-> ";
//            current = current->next;
//        }
//        cout << "NULL\n";
//    }
//
//    ~SortedDoublyLinkedList() {
//        makeEmpty();
//    }
//};
//
//int main() {
//    SortedDoublyLinkedList list;
//    list.insert(30);
//    list.insert(20);
//    list.insert(40);
//    list.insert(10);
//    list.printList(); // ���: 10 <-> 20 <-> 30 <-> 40 <-> NULL
//    list.remove(20);
//    list.printList(); // ���: 10 <-> 30 <-> 40 <-> NULL
//    list.makeEmpty();
//    list.printList(); // ���: NULL
//    return 0;
//}

template<typename T>
struct NodeType
{
	T data;
	NodeType* next;
};

template<typename T>
class SinglyLinkedList
{
public:

private:
	NodeType* pFirst;
	NodeType* pCurrent;
};



//pointer array�� ���� �Ҵ��Ͽ� ����ϴ� Sorted List�� �����Ͻÿ�.�����ڿ��� �ִ� �������� ������ �Է� �޾� pointer array�� ���� �Ҵ��ϰ� �� �������� ���� �ÿ��� ���� �Ҵ��� �������� pointer�� ����Ű���� �Ͻÿ�. (40��)
//
//
//Que�� Ȱ���Ͽ� 12���� ���������� �º� ���� ���� ���� ��� ���α׷��� �ۼ��Ͻÿ�. (100��)
//
//
//Red���� ���� ���� ���� ���� 4�����̸� ���� ������ �̸� �����Ǿ� �ִ�.
//Red���� ���� ���� ���� ���� ������ �⺻������ �̸� �����Ǿ� ������ �� �� 4���� ������� ���� ������������ ������ �Ŀ� Ȯ���� �� �ִ�.
//Red���� �˷��� ���� ���� �� ������ ���� Blue���� ���� ���� �� ���� ������ �����Ѵ�.�� �� Blue�� ���� ���������� ������ 4�������� �����ؾ� �Ѵ�.
//�⺻������ ���� ���� ������ Blue���� �¸��ϸ� 1��, ���� 0��, ���� ?1���� ��´�.
//�ٸ�, ���� ���ʽ��� ����Ǿ� Blue���� �¸��� ��� �������� ���¼��� ������ �߰��ȴ�.���� ������ �������� ������ ���� ���ʽ��� �����Ǹ� ���� �� ��� ���� ���ʽ��� �ʱ�ȭ�Ǿ� 0���� �ٽ� ���۵ȴ�.
//�� ������ �����Ͽ� Red���� ������ Blue���� 12�� ���������� ������ ��� �����ϸ� �º� ���� �ܰ迡 ����.
//���� ���� ���� ����Ǳ� �� Blue���� �������� ��, ��, �� ������ �����ϸ� ���� ��� ���� �¸� �� 1, ���º� �� 2, �й� �� 3���� ���ʽ� ������ ��� �ȴ�.
//
//
//����) Red �� �Է��� ������ ����(ū ����ǥ�� ���� ���� �����)
//
//[����, ��������, ����, ����, ��, ������, ����, ��, ����, ��, ��������, ��������]
//
//Blue �� �Է��� �Ʒ��� ���� �������� ��
//
//[����, ��, ����, ��, ����, ��, ����, ����, ����, ����, ��, ����]
//
//1��° ���� ���� ���� ����� �����Ǿ� �־� ���� �̸� ������ �� �ְ�, �� ��°�� ������� ����� �����ؾ� �Ѵ�.�Ʒ��� ���� �� ���� ���� �� �� �º� ������ �ߴٰ� �� ��
//
//[��, ��, ��, ��, ��, ��, ��, ��, ��, ��, ��, ��]
//
//���������� ����� 1 + 2(1 + ����1) + 3 + 4 + 5 + 0 + 5 + 6 + 7 + 8 + 9 ?1 = 49�� �º� ���� ���� 1 + 0 + 1 + 1 + 1 + 2 + 1 + 1 + 1 + 1 + 0 + 0 = 10, ���� ������ 59���� �ȴ�.
//
//
//
//(���ʽ�)������ �ִ� ������ ���� �� �ֵ��� Blue�� ���������� ������ �º� ������ �����ϴ� �Լ��� �����Ͻÿ�. (30��)