#include <iostream>
#include "Student.h"
#include "QuickSort.h"
#include <string>

using namespace std;

int main() {
    Student stu;

    stu.InitValue(0, 2003200111, "�̿���", 3.0);
    stu.InitValue(1, 2004200121, "�ǿ���", 3.2);
    stu.InitValue(2, 2005200132, "������", 2.7);

    QuickSort(stu, 0, stu.GetStudentNum() - 1);

    for (int i = 0; i < stu.GetStudentNum(); i++) {
        stu.GetStudentInfo(i);
    }

    return 0;
}
