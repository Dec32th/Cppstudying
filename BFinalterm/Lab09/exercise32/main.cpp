#include<iostream>
#include"TreeType.h"
using namespace std;

int Smaller(TreeType tree, int value)
{
	ItemType item;
	bool finished = false;
	int count = 0;

	tree.ResetTree(IN_ORDER);

	do {
		tree.GetNextItem(item, IN_ORDER, finished);

		if (item < value &&!finished)
			count++;
		else
			finished = true;
	} while (!finished);
	return count;
}

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

    // Smaller �Լ� �׽�Ʈ
    int value = 'E';
    int count = Smaller(tree, value);
    cout << "Number of nodes smaller than " << static_cast<char>(value) << ": " << count << endl;
}