#pragma once
#include "../Head.h"


class MyString
{
public:
	MyString();
	MyString(const char* data);
	MyString(const MyString& str);

	//String& operator = (const String& str)
	//{
	//	if (this!=&str)
	//	{
	//		int len = str.Size();
	//		delete[] data;
	//		data = new char[len + 1];
	//		strcpy(data, str.data);
	//	}
	//	return *this;
	//};

	MyString& operator = (MyString str);

	~MyString();

	int Size() const;

	char& operator[] (int index) const;

	friend istream& operator >> (istream& is, MyString& str);

	friend ostream& operator << (ostream& os, const MyString& str);
private:
	char* data;
};