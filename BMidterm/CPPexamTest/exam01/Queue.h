#pragma once
class Queue
{

};

//ť

//#include <iostream>
//
//class Queue {
//private:
//    int front;      // ť�� �պκ��� ����Ű�� �ε���
//    int rear;       // ť�� �޺κ��� ����Ű�� �ε���
//    int capacity;   // ť�� �ִ� �뷮
//    int* queue;     // ť�� ��Ҹ� �����ϴ� ���� �迭
//
//public:
//    // ������: ť�� ũ�⸦ �����ϰ� �������� �ʱ�ȭ�մϴ�.
//    Queue(int c) {
//        front = rear = 0;
//        capacity = c;
//        queue = new int[capacity];
//    }
//
//    // �Ҹ���: �������� �Ҵ�� �迭�� �����մϴ�.
//    ~Queue() {
//        delete[] queue;
//    }
//
//    // ť�� �����͸� �߰��ϴ� �Լ�
//    void enqueue(int data) {
//        if (capacity == rear) { // ť�� ���� á���� �˻�
//            std::cout << "Queue is full\n";
//            return;
//        }
//        else {
//            queue[rear] = data; // rear ��ġ�� ������ ����
//            rear++;             // rear�� �ϳ� ����
//        }
//    }
//
//    // ť���� �����͸� �����ϰ� ��ȯ�ϴ� �Լ�
//    int dequeue() {
//        if (front == rear) { // ť�� ��� �ִ��� �˻�
//            std::cout << "Queue is empty\n";
//            return -1;
//        }
//        else {
//            int item = queue[front]; // front ��ġ�� �����͸� ������
//            for (int i = 0; i < rear - 1; i++) { // ť�� �����͸� ������ �̵�
//                queue[i] = queue[i + 1];
//            }
//            rear--; // rear�� �ϳ� ����
//            return item; // ���ŵ� ���� ��ȯ
//        }
//    }
//
//    // ť�� �� �� ���Ҹ� ��ȯ�ϴ� �Լ�
//    int peek() {
//        if (front == rear) { // ť�� ��� �ִ��� Ȯ��
//            std::cout << "Queue is empty\n";
//            return -1;
//        }
//        else {
//            return queue[front]; // front ��ġ�� ������ ��ȯ
//        }
//    }
//
//    // ť�� ����ִ��� Ȯ���ϴ� �Լ�
//    bool isEmpty() {
//        return (front == rear);
//    }
//};
//
//int main() {
//    Queue q(5);
//
//    q.enqueue(10);
//    q.enqueue(20);
//    q.enqueue(30);
//    std::cout << "Dequeued: " << q.dequeue() << std::endl;
//    std::cout << "Front item: " << q.peek() << std::endl;
//
//    return 0;
//}


//���� ť
//#include <iostream>
//using namespace std;
//
//class CircularQueue {
//private:
//    int* queue;
//    int front;
//    int rear;
//    int capacity;
//
//public:
//    CircularQueue(int size) {
//        capacity = size;
//        queue = new int[capacity];
//        front = 0;
//        rear = 0;
//    }
//
//    ~CircularQueue() {
//        delete[] queue;
//    }
//
//    // ť�� ����ִ��� Ȯ��
//    bool isEmpty() {
//        return front == rear;
//    }
//
//    // ť�� ���� á���� Ȯ��
//    bool isFull() {
//        return (rear + 1) % capacity == front;
//    }
//
//    // ��� ����
//    void enqueue(int data) {
//        if (isFull()) {
//            cout << "Queue is full!" << endl;
//            return;
//        }
//        queue[rear] = data;
//        rear = (rear + 1) % capacity;
//    }
//
//    // ��� ����
//    int dequeue() {
//        if (isEmpty()) {
//            cout << "Queue is empty!" << endl;
//            return -1;
//        }
//        int data = queue[front];
//        front = (front + 1) % capacity;
//        return data;
//    }
//
//    // ť ������ ��� Ȯ��
//    int peek() {
//        if (isEmpty()) {
//            cout << "Queue is empty!" << endl;
//            return -1;
//        }
//        return queue[front];
//    }
//
//    // ť ���
//    void printQueue() {
//        if (isEmpty()) {
//            cout << "Queue is empty!" << endl;
//            return;
//        }
//        int i = front;
//        cout << "Queue contents: ";
//        while (i != rear) {
//            cout << queue[i] << " ";
//            i = (i + 1) % capacity;
//        }
//        cout << endl;
//    }
//};
//
//int main() {
//    CircularQueue q(5); // �����δ� 4���� ��Ҹ� ���� ����
//
//    q.enqueue(1);
//    q.enqueue(2);
//    q.enqueue(3);
//    q.enqueue(4);
//    q.printQueue();
//
//    q.dequeue();
//    q.dequeue();
//    q.printQueue();
//
//    q.enqueue(5);
//    q.enqueue(6);
//    q.printQueue();
//
//    return 0;
//}

