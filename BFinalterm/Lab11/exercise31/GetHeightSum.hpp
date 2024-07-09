#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

template <class ItemType>
int GetHeightSum(ItemType values[], int numValues);

template <class ItemType>
int GetHeight(ItemType values[], int start, int numValues);

template <class ItemType>
int GetHeightSum(ItemType values[], int numValues) {
    int index, sum = 0;
    // non-leaf ��忡 ���� �� ��带 ��Ʈ�� �ϴ� subtree�� height ���
    for (index = numValues / 2 - 1; index >= 0; index--)
        sum += GetHeight(values, index, numValues - 1);

    cout << "sum of heights = " << sum << endl;
    return sum;
}

template <class ItemType>
int GetHeight(ItemType values[], int start, int numValues) {
    if (start > numValues) return 0; // start�� leaf�̰ų� tree �ۿ� �ִ� ���
    int l_height = GetHeight(values, 2 * start + 1, numValues); // left subtree�� height
    int r_height = GetHeight(values, 2 * start + 2, numValues); // right subtree�� height
    return max(l_height, r_height) + 1; // ��subtree height �� ū �� + 1�� �� ����
}

// Helper function to print the tree for visualization
template <class ItemType>
void PrintTree(ItemType values[], int numValues, int index, int indent = 0) {
    if (index < numValues) {
        if (2 * index + 2 < numValues)
            PrintTree(values, numValues, 2 * index + 2, indent + 4);

        if (indent)
            cout << setw(indent) << ' ';
        if (2 * index + 2 < numValues)
            cout << " /\n" << setw(indent) << ' ';

        std::cout << values[index] << "\n ";

        if (2 * index + 1 < numValues) {
            cout << setw(indent) << ' ' << " \\\n";
            PrintTree(values, numValues, 2 * index + 1, indent + 4);
        }
    }
}