//����Լ����� for���� �� ������ ����Ų�ٰ� �����Ѵ�. 
//����Լ��� ����ϴ� ��쿡�� �Լ��� ȣ���ϴ� �������� stack memory�� ����ϰ� �Ǵµ�, �Ǻ���ġ ������ ���
//2������ �������鼭 ���� stack memory�� ����ϰ� �ǰ�, stack overflow�� �߻��ϴ� ������ �� �� �ִ�.
//���� bigOǥ������ �̿��Ͽ� ���� ��쿡�� �ð����⵵�� ����Լ��� �ξ� �� ���ڴ�. 


#include <iostream>
#include"Fibonacci.h"
using namespace std;

int Fibonacci_recursive(int n);
int Fibonacci_non_recursive(int n);

int main()
{
	cout << Fibonacci_recursive(10) << endl;
	cout << Fibonacci_non_recursive(10) << endl;

	return 0;
}
