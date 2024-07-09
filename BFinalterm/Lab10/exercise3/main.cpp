#include<iostream>
#include"Heap.h"
using namespace std;

int main()
{
    // HeapType �ν��Ͻ� ����
    HeapType<int> heap;
    heap.numElements = 5;
    heap.elements = new int[heap.numElements];

    // ������ ������ ���� ä���
    int values[] = { 10, 20, 5, 30,25 };
    for (int i = 0; i < heap.numElements; ++i) {
        heap.elements[i] = values[i];
    }

    // ���� ��� ���
    cout << "Initial heap elements: ";
    for (int i = 0; i < heap.numElements; ++i) {
        cout << heap.elements[i] << " ";
    }
    cout << endl;

    //// ReheapDown �׽�Ʈ
    heap.ReheapDown(0, heap.numElements - 1);

    // ReheapDown �� ���� ��� ���
    cout << "Heap elements after ReheapDown: ";
    for (int i = 0; i < heap.numElements; ++i) {
        cout << heap.elements[i] << " ";
    }
    cout << endl;

    // ReheapUp �׽�Ʈ
    heap.elements[4] = 35;
    heap.ReheapUp(0, heap.numElements - 1);

    // ReheapUp �� ���� ��� ���
    cout << "Heap elements after ReheapUp: ";
    for (int i = 0; i < heap.numElements; ++i) {
        cout << heap.elements[i] << " ";
    }
    cout << endl;

    // ���� �迭 ����
    delete[] heap.elements;

    return 0;
}

//heap�� �־��� ��쿡�� O(log_2n)�� �����Ѵ�.  
//�׸��� reheapdown�� reheapup �Ѵ� �־��� ��쿡�� Ʈ���� ���̿� ����ؼ� �����Ѵ�.
// ���� ���� �ð����⵵�� O(logn)