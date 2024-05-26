#include <cmath>
#include<iostream>
using namespace std;

//main �Լ� �ۼ�.  ���ο��� �Լ����� ȣ��. 
//(SqrRoot�� Ŭ������ ���� ����ϼŵ� �˴ϴ�.)

//��� ����. ������ ���� ������ �����ø� �˴ϴ�.
float SqrRoot_recursion(float number, float approx, float tol)
{
	if (fabs(approx * approx - number) <= tol)
		return approx;
	else
		return SqrRoot_recursion(number, (approx * approx + number) / (2 * approx), tol);
}


//����� ����. ��� �������� �ݺ������� ����ϴ� �κ��� ���ǿ� ���� ������ �˴ϴ�.
float SqrRoot_non_recursion(float number, float approx, float tol)
{
	while (fabs(approx * approx - number) > tol)
	{
		approx = (approx * approx + number) / (2 * approx);
	}
	return approx;
}

int main()
{
	cout << "��� �Լ� �̿� : " << SqrRoot_recursion(2, 1, 0.1);
	cout << "����� �Լ� �̿� : " << SqrRoot_non_recursion(2, 1, 0.1);
}
