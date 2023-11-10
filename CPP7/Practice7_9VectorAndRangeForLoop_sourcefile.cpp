//Practice 7 #9 Range-Based for loop & vector Reverse & Random value generate

//�ǽ� 7 - ũ�Ⱑ 5�� [0,99]�� ������ ���� �����ϴ� vector�� �����, �� ���� ������ �������� �ٲٴ� Reverse�Լ��� �����϶�.
#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
using namespace std;

//������� for��. vector�� ���ҿ� ����, �� ���� ���.
void print(const vector<int>& v)
{
    for (const auto& x : v)
    {
        cout << x << " ";
    }
    cout << endl;
}

//������ ����� ������ �������� �ٲپ� �ִ� Reverse�Լ�
vector<int> Reverse(vector<int> v)
{
    for (int i = 0; i < v.size() / 2; i++)
    {
        int t = v[i];
        v[i] = v[v.size() - i - 1];
        v[v.size() - i - 1] = t;
    }
    return v;
}

int main()
{
    vector<int> v1;

    //[0,99]�� random�� ���� �ð��� seed�� �ؼ� ����� �� ���� vector�� ����.
    srand(static_cast<unsigned>(time(0)));
    for (int i = 0; i < 5; i++)
    {
        v1.push_back(rand() % 100);
    }

    //Reverse function call
    vector<int> v2 = Reverse(v1);

    print(v1);
    print(v2);

}