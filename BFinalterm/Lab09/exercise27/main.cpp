#include<iostream>
#include"TreeType.h"
using namespace std;

int main()
{
    TreeType tree;

    // Ʈ�� ���� (������ ���)
    tree.InsertItem('F');
    tree.InsertItem('B');
    tree.InsertItem('G');
    tree.InsertItem('A');
    tree.InsertItem('D');
    tree.InsertItem('C');
    tree.InsertItem('E');
    tree.InsertItem('I');
    tree.InsertItem('H');

    // Ancestors �Լ� �׽�Ʈ
    ItemType value = 'E';
    cout << "Ancestors of " << value << ": ";
    tree.Ancestors_re(value);
}