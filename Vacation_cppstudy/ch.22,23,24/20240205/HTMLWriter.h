#pragma once

#include"DocWriter.h"

class HTMLWriter : public DocWriter
{
public:
	HTMLWriter();
	~HTMLWriter();
	
	// �ؽ�Ʈ�� ���Ϸ� �����Ų��. 
	void Write();

	//��Ʈ�� �����Ѵ�.
	void SetFont(const string& fileName, int fontSize, const string& fontColor);

protected:
	string _fontName;
	int _fontSize;
	string _fontColor;

};