#include<iostream>
#include<cmath>

using namespace std;


class Point
{
public:
	//��� ����
	int x, y;
	//��� �Լ�
	void Print();

	Point();
	Point(int initialX, int initialY);
	Point(const Point& pt);
};

//������ �ܺο� ����
Point::Point()
{
	x = 0;
	y = 0;
}


Point::Point(int initialX, int initialY)
{
	x = initialX;
	y = initialY;
}

Point::Point(const Point& pt)
{
	cout << "���� ������ ȣ��" << endl;
	x = pt.x;
	y = pt.y;
}

void Point::Print()
{
	cout << "( " << x << ",  " << y << " )" << endl;
}


int main()
{
	//��ü�� �����Ѵ�.
	Point pt1(100, 100), pt2(200,200);


	//��ü�� �ʱ�ȭ �� ���� ��������ڰ� ȣ��ȴ�. (�� �� �����ڴ� ȣ����� �ʴ´�.)
	Point pt3 = pt1;

	//pt�� ������ ���
	pt3.Print();

	//���� ������ ���� ��µ��� �ʴ´�.
	pt3 = pt2;
	
	pt3.Print();


}