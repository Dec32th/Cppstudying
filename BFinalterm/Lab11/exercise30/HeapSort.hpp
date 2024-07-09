using namespace std;

template <class ItemType>
void Swap(ItemType& a, ItemType& b);

template <class ItemType>
void ReheapDown(ItemType values[], int root, int bottom);

template <class ItemType>
void HeapSort(ItemType values[], int numValues)
// Post: Sorts array values[ 0 . . numValues-1 ] into 
// ascending order by key
{
    int index;

    // �迭 �Է��� ����Ͻÿ� 
    cout << "Initial array: ";
    for (int i = 0; i < numValues; ++i)
        cout << values[i] << " ";
    cout << std::endl;

    // Convert array values[0..numValues-1] into a heap
    for (index = numValues / 2 - 1; index >= 0; index--)
        ReheapDown(values, index, numValues - 1);

    // Heap���� ����� �迭�� ����Ͻÿ� 
    cout << "Array converted to heap: ";
    for (int i = 0; i < numValues; ++i)
        cout << values[i] << " ";
    cout << endl;

    // Sort the array.
    for (index = numValues - 1; index >= 1; index--)
    {
        Swap(values[0], values[index]);
        ReheapDown(values, 0, index - 1);

        // ����� �迭�� ����Ͻÿ�
        cout << "Array after extracting max and reheapifying: ";
        for (int i = 0; i < numValues; ++i)
            cout << values[i] << " ";
        cout << endl;
    }
}

// Helper function to swap two elements
template <class ItemType>
void Swap(ItemType& a, ItemType& b) {
    ItemType temp = a;
    a = b;
    b = temp;
}

// Helper function to perform reheap down
template <class ItemType>
void ReheapDown(ItemType values[], int root, int bottom) {
    int maxChild;
    int rightChild;
    int leftChild;

    leftChild = root * 2 + 1;
    rightChild = root * 2 + 2;

    if (leftChild <= bottom) {
        if (rightChild <= bottom && values[rightChild] > values[leftChild])
            maxChild = rightChild;
        else
            maxChild = leftChild;

        if (values[root] < values[maxChild]) {
            Swap(values[root], values[maxChild]);
            ReheapDown(values, maxChild, bottom);
        }
    }
}