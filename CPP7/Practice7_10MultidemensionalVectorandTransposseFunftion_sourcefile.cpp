//Practice 7 #10 multidemensional vector print and Transpose function

//�ǽ� 7 - ���������Ϳ� [0,99]�� ������ ���� �����ϰ�, Transpose�� �ϴ� �Լ��� �����Ͽ���.
#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
using namespace std;

//������ ���� ����� ���� print�Լ� - Range-based for��
void print(const vector<vector<int>> &v)
{
    for (const auto &x : v)
    {
        for (const auto& elem : x)
        {
            cout << elem << " ";
        }
        cout << endl;
    }
    cout << endl;
}

//Transpose�Լ� - ��� ���� �ٲپ� �ش�.
vector<vector<int>> Transpose(vector<vector<int>> v)
{
    //�� - 2�� - ����
    int iRow = v[0].size();
    //�� - 3�� - ����
    int iColumn = v.size();
    vector<vector<int>> v1(iRow, vector<int>(iColumn, 0));

    for (int i = 0; i < iRow; i++)
    {
        for (int k = 0; k < iColumn; k++) 
        {
            v1[i][k] = v[k][i];
        }
    }
    
    return v1;
}

int main()
{
    srand(static_cast<unsigned>(time(0)));
    vector<vector<int>> m1 = { {0,0},{0,0}, {0,0} };


    //[0 - 99] ���� �� ������ �� �Ҵ�
    for (int i = 0; i < m1.size() ; i++)
    {
        for (int j = 0; j < m1[i].size(); j++)
        {
            m1[i][j] = rand() % 100;
        }

    }

    //Transpose�Լ��� �̿��ؼ� m2�� �����ϰ� �ʱ�ȭ��
    vector<vector<int>> m2 = Transpose(m1);

    //m1,m2���
    print(m1);
    print(m2);

}