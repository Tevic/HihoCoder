#include "MyString.h"
#include "stdio.h"


MyString::MyString() :data(new char[1]{ '\0' }) {}

MyString::MyString(const char* data)
{
	if (!data)
	{
		this->data = new char[1]{ '\0' };
	}
	else
	{
		int len = strlen(data);
		this->data = new char[len + 1]{ '\0' };
		strcpy(this->data, data);
	}
}

MyString::MyString(const MyString& str)
{
	int len = str.Size();
	this->data = new char[len + 1]{ '\0' };
	strcpy(this->data, str.data);
}

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

MyString& MyString::operator = (MyString str)
{
	swap(data, str.data);
	return *this;
};

MyString::~MyString()
{
	delete[] data;
};

int MyString::Size() const
{
	return strlen(data);
}

char& MyString::operator[] (int index) const
{
	int len = strlen(data);
	if (index <= len)
	{
		return data[index];
	}
	else
	{
		return data[len];
	}
}

ostream& operator << (ostream& os, const MyString& str)
{
	os << str.data;
	return os;
}

istream& operator >> (istream& is, MyString& str)
{
	char tmp;
	int len = str.Size();
	memset(str.data, 0, (len + 1)*sizeof(char));
	if (len == 0)
	{
		str.data = new char[2]{ '\0' };
		len = 1;
	}
	is.get(tmp);
	int index = 0;
	while (tmp != '\n')
	{
		if (index >= len)
		{
			char* newData = new char[len * 2 + 1]{ '\0' };
			len *= 2;
			strcpy(newData, str.data);
			delete[] str.data;
			str.data = newData;
		}
		str[index] = tmp;
		index++;
		is.get(tmp);
	}
	return is;
}