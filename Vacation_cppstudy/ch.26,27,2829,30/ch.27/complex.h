#pragma once
//���Ҽ� Ŭ����
class Complex
{
public:
	//constructor
	Complex(int realPart, int imaginaryPart)
		:real(realPart), imaginary(imaginaryPart)
	{}

	//accessor
	int Real(int realPart) { real - realPart; return real; }
	int Imaginary(int ImaginaryPart) { imaginary = ImaginaryPart; return imaginary; }

	int Real() const { return real; }
	int Imaginary() const { return imaginary; }

	friend Complex operator+(const Complex& left, const Complex& right);

	//C++ ��ġ����
	Complex operator++()
	{
		//�Ǽ����� ���� ���� ���Ѵ�
		this->real++;

		//���� ���� ��ȯ�Ѵ�
		return *this;
	}

	//C++ ��ġ����
	Complex operator++(int)
	{
		//���� ���� ���� �����Ѵ�
		Complex prev(this->real, this->imaginary);

		//�Ǽ����� ���� ���Ѵ�.
		this->real++;

		//������ ���� ��ȯ�Ѵ�
		return prev;
	}

	//C++ ��ġ����
	Complex operator--()
	{
		//�Ǽ����� ���� ���� ����
		this->real--;

		//���� ���� ��ȯ
		return *this;
	}

	//C++ ��ġ����
	Complex operator--(int)
	{
		//�Ǽ����� ���� ���� ����
		Complex prev(this->real, this->imaginary);

		//�Ǽ����� ���� ����
		this->real--;

		//������ ���� ��ȯ
		return prev;


	}

private:
	int real;			//�Ǽ���
	int imaginary;		//�����
};