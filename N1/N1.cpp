#include "../Head.h"


string PreInput(string inStr)
{
	unordered_set<char> st = { '9','7','0','6' };
	string result;
	int len = inStr.size();
	for (int i = 0; i < len; i++)
	{
		if (st.find(inStr[i]) != st.end())
		{
			result += inStr[i];
		}
	}
	return result;
}

int GetCount(string& strPattern)
{
	int iCount = 0;
	int index = 0;
	int len = strPattern.size();
	if (len<4)
	{
		return 0;
	}

	while (index<len)
	{
		while (index < len&&strPattern[index] != '9')index++;
		if (index == len)break;
		strPattern[index] = 'X';
		while (index < len&&strPattern[index] != '7')index++;
		if (index == len)break;
		strPattern[index] = 'X';
		while (index < len&&strPattern[index] != '0')index++;
		if (index == len)break;
		strPattern[index] = 'X';
		while (index < len&&strPattern[index] != '6')index++;
		if (index == len)break;
		strPattern[index] = 'X';
		iCount++;
		index = 0;
	}
	return iCount;
}



int main()
{
	//ReOpenText();
	int nCount = 0;
	cin >> nCount;
	for (int i = 0; i < nCount; i++)
	{
		string strPattern;
		cin >> strPattern;
		strPattern = PreInput(strPattern);
		cout << GetCount(strPattern) << endl;
	}
}