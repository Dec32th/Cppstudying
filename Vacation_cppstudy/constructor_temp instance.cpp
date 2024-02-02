//�����ڸ� ����ؼ� �ӽð�ü �����

#include<iostream>

using namespace std;

class Point
{
public:
	//memeber variable
	int x, y;

	//member function
	void Print()
	{
		cout << "( " << x << ", " << " )" << endl;
	}

	//constructors
	Point()
	{
		x = 0;
		y = 0;
	}
	Point(int initialX, int initialY)
	{
		x = initialX;
		y = initialY;
	}
	Point(const Point& pt)
	{
		x = pt.x;
		y = pt.y;
	}
};


//Point ��ü�� ���ڷ� �䱸�ϴ� �Լ�
void Area(const Point& pt)
{
	//(0,0)�� pt�� �̷�� �簢���� ������ ���Ѵ�.
	int area = pt.x * pt.y;

	//��� ���
	cout << "(0, 0)�� �̷�� �簢���� ���� = " << area << endl;
}



int main()
{
	//����, x�� y�� �������� ������ �ִٰ� ����
	int x = 5;
	int y = 5;


	//�Լ� ȣ�� -  ���� instance�� ������ �ʰ� �����ڸ� �̿��ؼ� �ӽ� Point instance�� ����� �װ��� parameter��
	Area(Point(x,y));
	//���� ��, �ӽ� instance �Ҹ�.

}