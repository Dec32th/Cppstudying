//Practice 6 #7 Mathmatics Average 


//7�� ���� - EOF�Է��� ������ ������ ������ �Է¹ް� �� ���� �̿��ؼ� ���, ����, ��ȭ ����� ���Ͻÿ�.

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    //���� ���� �Է� ���� ������ dNum, �Է� �޴� ���� �̿��ؼ� ���, ������ ���� ������ ����
    //���, ����, ��ȭ ����� �Է°� 0���� ���� �� �ʱ�ȭ

    double dNum = 0;     //�Է� ����.

    double dSum = 0;     //������ ��� �߰���

    double dMul = 1;     //������� ��� �߰���

    double dRevSum = 0;  //��ȭ��� ��� �߰���

    double dAmean = 0;   //��� ��� ����

    double dGmean = 0;   //���� ��� ����

    double dHarmean = 0; //��ȭ ��� ����

    int iCount = 0;      //������ ���� ����

    
    

    //do - while���� �̿��ؼ� ���� 1�� �Է¹ް� �Ǵ�. EOF�Է� �� �ߴ�.
    do
    {

        cout << "0�̻��� �Ǽ��� �Է����ּ��� : ";
        cin >> dNum;

        //if���� �̿��ؼ� EOF�� �ԷµǾ����� �Ǵ�.
        if (cin.eof())
        {
            break;
        }

        //���, ����, ��ȭ����� ���.
        dSum += dNum;
        cout << "dSum  = " << dSum << endl;
        dMul *= dNum;
        cout << "dMul  = " << dMul << endl;
        dRevSum += 1. / dNum;
        iCount++;
    } while (!cin.eof());

    dAmean = dSum / iCount;
    dGmean = pow(dMul, 1. / iCount);
    dHarmean = 1. / dRevSum;

    //���, ����, ��ȭ ��� ���.

    cout << "dAmean�� ��: " << dAmean << endl;
    cout << "dGmean�� ��: " << dGmean << endl;
    cout << "dHarmean�� ��: " << dHarmean << endl;
}