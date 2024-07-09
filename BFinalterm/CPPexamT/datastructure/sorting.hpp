#pragma once
using namespace std;
#include <vector>

class Sorting {
public:
    static void quickSort(std::vector<int>& arr, int left, int right) {
        if (left >= right) return;
        int pivot = arr[(left + right) / 2];
        int index = partition(arr, left, right, pivot);
        quickSort(arr, left, index - 1);
        quickSort(arr, index, right);
    }

    static void mergeSort(std::vector<int>& arr, int left, int right) {
        if (left >= right) return;
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }

    static void heapSort(std::vector<int>& arr) {
        buildMaxHeap(arr);
        for (int i = arr.size() - 1; i >= 1; --i) {
            std::swap(arr[0], arr[i]);
            maxHeapify(arr, 0, i);
        }
    }

    static void selectionSort(std::vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n - 1; ++i) {
            int minIndex = i;
            for (int j = i + 1; j < n; ++j) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }
            std::swap(arr[i], arr[minIndex]);
        }
    }

    static void bubbleSort(std::vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (arr[j] > arr[j + 1]) {
                    std::swap(arr[j], arr[j + 1]);
                }
            }
        }
    }

    static void insertionSort(std::vector<int>& arr) {
        int n = arr.size();
        for (int i = 1; i < n; ++i) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                --j;
            }
            arr[j + 1] = key;
        }
    }

private:
    static int partition(std::vector<int>& arr, int left, int right, int pivot) {
        while (left <= right) {
            while (arr[left] < pivot) ++left;
            while (arr[right] > pivot) --right;
            if (left <= right) {
                std::swap(arr[left], arr[right]);
                ++left;
                --right;
            }
        }
        return left;
    }

    static void merge(std::vector<int>& arr, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;
        std::vector<int> L(n1);
        std::vector<int> R(n2);

        for (int i = 0; i < n1; ++i) L[i] = arr[left + i];
        for (int i = 0; i < n2; ++i) R[i] = arr[mid + 1 + i];

        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k++] = L[i++];
            }
            else {
                arr[k++] = R[j++];
            }
        }
        while (i < n1) arr[k++] = L[i++];
        while (j < n2) arr[k++] = R[j++];
    }

    static void buildMaxHeap(std::vector<int>& arr) {
        int n = arr.size();
        for (int i = n / 2 - 1; i >= 0; --i) {
            maxHeapify(arr, i, n);
        }
    }

    static void maxHeapify(std::vector<int>& arr, int i, int n) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[left] > arr[largest]) largest = left;
        if (right < n && arr[right] > arr[largest]) largest = right;

        if (largest != i) {
            std::swap(arr[i], arr[largest]);
            maxHeapify(arr, largest, n);
        }
    }
};


//���� �̿��ؼ� k��° ���� �� ã��
//#include <iostream>
//#include <vector>
//#include <queue>
//
//int findKthSmallest(const std::vector<int>& nums, int k) {
//    std::priority_queue<int> maxHeap;
//    for (int num : nums) {
//        maxHeap.push(num);
//        if (maxHeap.size() > k) {
//            maxHeap.pop();
//        }
//    }
//    return maxHeap.top();
//}
//
//int main() {
//    std::vector<int> nums = { 7, 10, 4, 3, 20, 15 };
//    int k = 3;
//    std::cout << "Kth smallest element is " << findKthSmallest(nums, k) << std::endl;
//    return 0;
//}


//������ ���� ����
//#include <iostream>
//#include <vector>
//
//// �⺻ ���� ���� �Լ�
//void bubbleSort(std::vector<int>& arr) {
//    int n = arr.size();
//    bool swapped;
//
//    // ����Ʈ�� ũ�⸸ŭ �ݺ��մϴ�.
//    for (int i = 0; i < n - 1; ++i) {
//        swapped = false;
//        // ������ ��ҵ��� ���ϰ� ��ȯ�մϴ�.
//        for (int j = 0; j < n - i - 1; ++j) {
//            if (arr[j] > arr[j + 1]) {
//                std::swap(arr[j], arr[j + 1]);
//                swapped = true; // ��ȯ�� �Ͼ���� ǥ��
//            }
//        }
//        // ��ȯ�� �����ٸ� ����Ʈ�� ���ĵ� �����̹Ƿ� �����մϴ�.
//        if (!swapped) {
//            break;
//        }
//    }
//}
//
//// ������ ���� ���� �Լ�
//void improvedBubbleSort(std::vector<int>& arr) {
//    int n = arr.size();
//    int lastSwapped = n - 1; // ���������� ��ȯ�� �Ͼ ��ġ�� �����մϴ�.
//
//    // ������ ��ȯ ��ġ�� 0���� Ŭ ������ �ݺ��մϴ�.
//    while (lastSwapped > 0) {
//        int newSwapped = 0; // ���ο� ��ȯ ��ġ�� �ʱ�ȭ�մϴ�.
//
//        // ������ ��ҵ��� ���ϰ� ��ȯ�մϴ�.
//        for (int j = 0; j < lastSwapped; ++j) {
//            if (arr[j] > arr[j + 1]) {
//                std::swap(arr[j], arr[j + 1]);
//                newSwapped = j; // ���ο� ��ȯ ��ġ�� �����մϴ�.
//            }
//        }
//        // ������ ��ȯ ��ġ�� �����մϴ�.
//        lastSwapped = newSwapped;
//    }
//}
//
//int main() {
//    // �׽�Ʈ�� �迭
//    std::vector<int> arr = { 64, 34, 25, 12, 22, 11, 90 };
//
//    // ���� �迭 ���
//    std::cout << "Original array: ";
//    for (int i : arr) {
//        std::cout << i << " ";
//    }
//    std::cout << std::endl;
//
//    // �⺻ ���� ���� ����
//    bubbleSort(arr);
//
//    // �⺻ ���� ���ĵ� �迭 ���
//    std::cout << "Sorted array using basic Bubble Sort: ";
//    for (int i : arr) {
//        std::cout << i << " ";
//    }
//    std::cout << std::endl;
//
//    // �ٽ� ���ĵ��� ���� �迭�� �ʱ�ȭ
//    std::vector<int> arr2 = { 64, 34, 25, 12, 22, 11, 90 };
//
//    // ������ ���� ���� ����
//    improvedBubbleSort(arr2);
//
//    // ������ ���� ���ĵ� �迭 ���
//    std::cout << "Sorted array using improved Bubble Sort: ";
//    for (int i : arr2) {
//        std::cout << i << " ";
//    }
//    std::cout << std::endl;
//
//    return 0;
//}



//radix sort �˰���
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <cmath>
//
//// ���� �Լ�: ī���� ������ ����Ͽ� �ڸ������� ����
//void countingSort(std::vector<int>& arr, int exp) {
//    int n = arr.size();
//    std::vector<int> output(n);
//    int count[10] = { 0 };
//
//    // ���� �ڸ����� �ش��ϴ� ���� ������ ī��Ʈ
//    for (int i = 0; i < n; i++) {
//        count[(arr[i] / exp) % 10]++;
//    }
//
//    // ���� ī��Ʈ ���
//    for (int i = 1; i < 10; i++) {
//        count[i] += count[i - 1];
//    }
//
//    // ���� �ڸ��� �������� ����
//    for (int i = n - 1; i >= 0; i--) {
//        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
//        count[(arr[i] / exp) % 10]--;
//    }
//
//    // ���ĵ� �迭�� ���� �迭�� ����
//    for (int i = 0; i < n; i++) {
//        arr[i] = output[i];
//    }
//}
//
//// Radix Sort �Լ�
//void radixSort(std::vector<int>& arr) {
//    int maxVal = *std::max_element(arr.begin(), arr.end());
//
//    // 1�� �ڸ������� �����Ͽ� �ִ� �ڸ������� ����
//    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
//        countingSort(arr, exp);
//    }
//}
//
//int main() {
//    std::vector<int> arr = { 170, 45, 75, 90, 802, 24, 2, 66 };
//
//    std::cout << "Original array: ";
//    for (int num : arr) {
//        std::cout << num << " ";
//    }
//    std::cout << std::endl;
//
//    radixSort(arr);
//
//    std::cout << "Sorted array: ";
//    for (int num : arr) {
//        std::cout << num << " ";
//    }
//    std::cout << std::endl;
//
//    return 0;
//}
