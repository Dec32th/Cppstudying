//#include <iostream>
//#include <vector>
//#include <list>
//#include <string>
//
//// �ؽ� �Լ��� �����մϴ�.
//int hashFunction(int key, int tableSize) {
//    return key % tableSize;
//}
//
//// ��Ŷ ��� �ؽ� ���̺� Ŭ����
//class BucketHashTable {
//private:
//    int tableSize;
//    std::vector<std::list<int>> table; // �� ��Ŷ�� ����Ʈ�� �����մϴ�.
//
//public:
//    BucketHashTable(int size) : tableSize(size), table(size) {}
//
//    void insert(int key) {
//        int index = hashFunction(key, tableSize);
//        table[index].push_back(key);
//    }
//
//    bool search(int key) {
//        int index = hashFunction(key, tableSize);
//        for (int item : table[index]) {
//            if (item == key) {
//                return true;
//            }
//        }
//        return false;
//    }
//
//    void remove(int key) {
//        int index = hashFunction(key, tableSize);
//        table[index].remove(key);
//    }
//
//    void display() {
//        for (int i = 0; i < tableSize; ++i) {
//            std::cout << "Bucket " << i << ": ";
//            for (int item : table[i]) {
//                std::cout << item << " ";
//            }
//            std::cout << std::endl;
//        }
//    }
//};
//
//int main() {
//    BucketHashTable ht(7); // ũ�Ⱑ 7�� �ؽ� ���̺� ����
//
//    ht.insert(10);
//    ht.insert(20);
//    ht.insert(15);
//    ht.insert(7);
//    ht.insert(17);
//
//    ht.display();
//
//    std::cout << "Searching 15: " << (ht.search(15) ? "Found" : "Not Found") << std::endl;
//    std::cout << "Searching 21: " << (ht.search(21) ? "Found" : "Not Found") << std::endl;
//
//    ht.remove(15);
//    ht.display();
//
//    return 0;
//}

//
//#include <iostream>
//#include <vector>
//#include <list>
//#include <string>
//
//// �ؽ� �Լ��� �����մϴ�.
//int hashFunction(int key, int tableSize) {
//    return key % tableSize;
//}
//
//// ü�� ��� �ؽ� ���̺� Ŭ����
//class ChainHashTable {
//private:
//    int tableSize;
//    std::vector<std::list<int>> table; // �� ü���� ����Ʈ�� �����մϴ�.
//
//public:
//    ChainHashTable(int size) : tableSize(size), table(size) {}
//
//    void insert(int key) {
//        int index = hashFunction(key, tableSize);
//        table[index].push_back(key);
//    }
//
//    bool search(int key) {
//        int index = hashFunction(key, tableSize);
//        for (int item : table[index]) {
//            if (item == key) {
//                return true;
//            }
//        }
//        return false;
//    }
//
//    void remove(int key) {
//        int index = hashFunction(key, tableSize);
//        table[index].remove(key);
//    }
//
//    void display() {
//        for (int i = 0; i < tableSize; ++i) {
//            std::cout << "Chain " << i << ": ";
//            for (int item : table[i]) {
//                std::cout << item << " ";
//            }
//            std::cout << std::endl;
//        }
//    }
//};
//
//int main() {
//    ChainHashTable ht(7); // ũ�Ⱑ 7�� �ؽ� ���̺� ����
//
//    ht.insert(10);
//    ht.insert(20);
//    ht.insert(15);
//    ht.insert(7);
//    ht.insert(17);
//
//    ht.display();
//
//    std::cout << "Searching 15: " << (ht.search(15) ? "Found" : "Not Found") << std::endl;
//    std::cout << "Searching 21: " << (ht.search(21) ? "Found" : "Not Found") << std::endl;
//
//    ht.remove(15);
//    ht.display();
//
//    return 0;
//}
