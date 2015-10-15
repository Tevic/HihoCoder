#include "../Head.h"
#include "../GlobalFunc.h"

//int main()
//{
//	int N;
//	cin >> N;
//	string line;
//	int nCount = 0;
//	if (N<0)
//	{
//		cout << "false" << endl;
//	}
//	while (cin>>line)
//	{
//		if (line == "true")
//		{
//			nCount++;
//			if (N == nCount)
//			{
//				break;
//			}
//		}
//	}
//	if (nCount==N)
//	{
//		cout << "true" << endl;
//	}
//	else
//	{
//		cout << "false" << endl;
//	}
//	return 0;
//}

string GetMaxNumStr(string& strIn)
{
	int len = strIn.size();
	int startIndex = 0;
	int maxLen = 0;
	for (int i = 0; i < len; i++)
	{
		if (isdigit(strIn[i]))
		{
			int j = i;
			while (j<len&&isdigit(strIn[j]))
			{
				j++;
			}
			if (j-i>maxLen)
			{
				maxLen = j - i;
				startIndex = i;
			}
			else if(j - i==maxLen)
			{
				startIndex = strIn[i] > strIn[startIndex] ? i : startIndex;
			}
			i = j-1;
		}
	}
	return strIn.substr(startIndex, maxLen);
}

int main()
{
	string line;
	while (cin >> line)
	{
		cout << GetMaxNumStr(line) << endl;
	}
	return 0;
}