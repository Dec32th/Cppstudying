#pragma once

#include"DocWriter.h"

class HTMLWriter : public DocWriter
{
public:
	HTMLWriter();
	HTMLWriter(const string& fileName, const string& content);
	~HTMLWriter();
	
	// �ؽ�Ʈ�� ���Ϸ� �����Ų��. 
	virtual void Write();

	//��Ʈ�� �����Ѵ�.
	void SetFont(const string& fileName, int fontSize, const string& fontColor);

protected:
	string _fontName;
	int _fontSize;
	string _fontColor;

};