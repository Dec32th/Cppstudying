#include"HTMLWriter.h"
#include"DocWriter.h"

int main()
{
	//HTMLWriter ��ü ����
	HTMLWriter hw("test.html", "HTMLWriter Content");

	//DocWriter pointer�� ��ü�� ����Ų��
	DocWriter* pDW = &hw;

	pDW->Write();
}