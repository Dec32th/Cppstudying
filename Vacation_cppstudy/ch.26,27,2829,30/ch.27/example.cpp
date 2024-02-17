#include<iostream>
#include"complex.h"
using namespace std;


Complex operator+(const Complex& left, const Complex& right)
{
	//�Ǽ��ο� ����θ� ���� ���Ѵ�
	int real = left.real + right.real;
	int imag = left.imaginary + right.imaginary;

	//����� ������ ���Ҽ� ��ü�� ��ȯ�Ѵ�.
	return Complex(real, imag);
}

int main()
{
	Complex c1(1, 1);
	Complex c2(2, 2);
	Complex c3(0, 0);

	//+�����ڸ� ����� ����
	c3 = c1 + c2;
	c3 = operator+(c1, c2);

	cout << c3.Real() << endl;
	cout << c3.Imaginary() << endl;
}