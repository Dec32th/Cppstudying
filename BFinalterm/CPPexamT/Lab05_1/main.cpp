#include<iostream>
#include"CircularQue.hpp"
using namespace std;

int main()
{
    CircularQue<int> cq(3);

    cq.EnQue(3);
    cq.EnQue(4);
    cq.EnQue(5);

    int out;
    cq.DeQue(out);
    cout << out << endl; // ���: 3

    cq.EnQue(6);

    cq.DeQue(out);
    cout << out << endl; // ���: 4
    cq.DeQue(out);
    cout << out << endl; // ���: 5
    cq.DeQue(out);
    cout << out << endl; // ���: 6

    cq.EnQue(7);
    cq.DeQue(out);
    cout << out << endl; // ���: 7

    CircularQue<int> cq1(cq);
    
    cq1.DeQue(out);
    cout << out << endl; // ���: 7
}