#pragma once


//lab4 stack


//stack
//#include <iostream>
//#include <climits> // INT_MIN�� ����ϱ� ���� �ʿ�
//using namespace std;
//
//class Stack {
//private:
//    int top;        // ������ ���� ��� ��Ҹ� ����Ű�� �ε���
//    int capacity;   // ������ �ִ� �뷮
//    int* stack;     // ������ ��Ҹ� �����ϴ� ���� �迭
//
//public:
//    // ������: ������ ũ�⸦ �����ϰ� top�� -1�� �ʱ�ȭ�մϴ�.
//    Stack(int size) {
//        capacity = size;
//        stack = new int[capacity];
//        top = -1;
//    }
//
//    // �Ҹ���: �������� �Ҵ�� �迭�� �����մϴ�.
//    ~Stack() {
//        delete[] stack;
//    }
//
//    // ���ÿ� ��Ҹ� �߰��ϴ� �Լ�
//    void push(int value) {
//        if (top == capacity - 1) { // ������ ���� á���� �˻�
//            cout << "Stack Overflow" << endl;
//            return;
//        }
//        else {
//            stack[++top] = value; // top�� ������Ų �� �� ��ġ�� �� ����
//        }
//    }
//
//    // ���ÿ��� �ֻ��� ��Ҹ� �����ϰ� ��ȯ�ϴ� �Լ�
//    int pop() {
//        if (top == -1) { // ������ ��� �ִ��� �˻�
//            cout << "Stack Underflow" << endl;
//            return INT_MIN;
//        }
//        else {
//            return stack[top--]; // ���� top�� ��Ҹ� ��ȯ�ϰ� top�� ����
//        }
//    }
//
//    // ������ �ֻ��� ��Ҹ� ��ȯ�ϴ� �Լ� (�������� ����)
//    int peek() {
//        if (top == -1) { // ������ ��� �ִ��� �˻�
//            cout << "Stack is empty" << endl;
//            return INT_MIN;
//        }
//        else {
//            return stack[top]; // ���� top�� ��Ҹ� ��ȯ
//        }
//    }
//
//    // ������ ����ִ��� Ȯ���ϴ� �Լ�
//    bool isEmpty() {
//        return top == -1;
//    }
//};
//
//int main() {
//    Stack s(5);  // ������ ũ�⸦ 5�� ����
//
//    s.push(10);
//    s.push(20);
//    s.push(30);
//    cout << "Popped: " << s.pop() << endl;
//    cout << "Top element: " << s.peek() << endl;
//
//    return 0;
//}
