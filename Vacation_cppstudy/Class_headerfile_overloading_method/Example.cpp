#include"Point.h"

//void XX()������ �Լ��� ���� ������
typedef void (*FP1)(int);

//void Point::XX() ������ �Լ��� ���� ������
typedef void (Point::* FP2)(int);
int main()
{
	//��ü�� �����Ѵ�.
	Point pt(50, 50);
	Point delta(100, 100);

	//���� x������ 10, y������ -10��ŭ �̵���Ų��.
	pt.Offset(10, -10);

	//���� ���� ��ġ ��� (60,40)
	pt.Print();

	//���� ���� ������ �̵���Ų�� (100.100) -> �����ڸ� �̿��ؼ� ������ �����ϱ� �����̴�.
	pt.Offset(delta);

	//pt�� ������ ����Ѵ�.
	pt.Print();

}