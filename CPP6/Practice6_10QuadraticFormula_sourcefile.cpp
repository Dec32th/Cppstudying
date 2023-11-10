//Practice6_#10 Quardratic formula

//10�� ���� - ���� ������ �̿��ؼ� ������������ �ظ� ���ϴ� ���α׷��� �ۼ��Ͻÿ�

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    //2���������� ��� - ���� �ʱ�ȭ �� ����
    double a = 0;
    double b = 0;
    double c = 0;
    
    //2���������� �� �Ǳ� �� 1���������� �� ����.
    double x1, x2;
    double x;

    //2���������� ����� a,b,c ���� �Է� �ޱ�
    cout << "Enter the number(a): ";
    cin >> a;
    cout << "Enter the number(b): ";
    cin >> b;
    cout << "Enter the number(c): ";
    cin >> c;
    
   //if���� �̿��ؼ� Quardratic formula �Ի�

    //�������� �ƴ� ���.
    if (a == 0 && b == 0)
    {
        cout << "You enter the wrong number. Enter the right number.";
    }

    //2�� �������� �ƴ϶� 1���������� ���.
    else if (a == 0 && b != 0)
    {
        x = -c / b;
        cout << "x = " << x;
    }

    //2�� �������� ���� ��� - ����� ���.
    else if (b * b - 4 * a * c < 0)
    {
        cout << "There is not a real solution." << endl;
    }

    //2�� �������� ���� ��� - ���� �ٸ� �� �Ǳ��� ���& �߱��� ���
    else
    {
        x1 = (-b + sqrt(b * b - 4 * a * c)) / 2 * a;
        x2 = (-b - sqrt(b * b - 4 * a * c)) / 2 * a;
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
    }
}