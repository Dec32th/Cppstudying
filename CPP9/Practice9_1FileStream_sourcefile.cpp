//Practice 9 #1 file stream
//�ǽ� 9 1�� csv���� ����� �ڵ�


#include<iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;


//csv ������ �о���� �Լ�
void ReadCsv(std::string FileName, std::vector<std::vector<std::string>>& Data)
{
    //file�� �̸��� parameter�� �޾Ƽ� ������ ����.
    std::ifstream ifs;

    ifs.open(FileName);
    if (!ifs.is_open()) return;

    //file�� ������ �� �پ� �о���� ���� ���ڿ�, �� ������(,) ���� �� �ʱ�ȭ
    std::string LineString = "";
    std::string Delimeter = ",";
    
    //getline�� �̿��ؼ� �� �پ� �о���� ��ǥ�� ã�Ƽ� �� nFindPos�� �����Ѵ�.
    //���� line ���� ���� vector�� push_back�Ѵ�.
    //','�� ���� nPos�� ���� ��쿡�� nFIndPos�� LineString�� ���̿� ����, rowdata�� ���� vector�� push_back�Ѵ�
    while (getline(ifs, LineString))
    {
        std::vector<std::string> RowData;
        unsigned int nPos = 0, nFindPos;
        do {
            nFindPos = LineString.find(Delimeter, nPos);
            if (nFindPos == std::string::npos) nFindPos = LineString.length();

            RowData.push_back(LineString.substr(nPos, nFindPos - nPos));
            nPos = nFindPos + 1;
        } while (nFindPos < LineString.length());
        Data.push_back(RowData);
    }


    //file�� ������ ���� ���� �Ŀ��� close�� �̿��ؼ� ������ �ݴ´�.
    ifs.close();
}

int main()
{
    vector<vector<string>> list;
    ReadCsv("diabetes.csv", list);
    for (int i = 0; i < list.size(); i++)
    {
        cout << "data[" << i << "]";
        for (int j = 0; j < list[i].size(); j++)
        {
            std::cout << list[i][j] << " ";
        }
        std::cout << endl;
    }
}