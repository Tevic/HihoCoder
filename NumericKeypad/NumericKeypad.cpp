#include "..\Head.h"

vector<vector<int> > toValid = 
{
	vector < int > {0},
	vector < int > {0,1,2,3,4,5,6,7,8,9},
	vector < int > {0,2,3,5,6,8,9},
	vector < int > {3,6,9},
	vector < int > {0,4,5,6,7,8,9},
	vector < int > {0,5,6,8,9},
	vector < int > {6,9},
	vector < int > {0,7,8,9},
	vector < int > {0,9},
	vector < int > {9}
};

bool AToB(int A,int B)
{
	if (find(toValid[A].begin(), toValid[A].end(), B) != toValid[A].end())
	{
		return true;
	}
	return false;
}

//bool IsValid(int iNum)
//{
//	stringstream ss;
//	ss << iNum;
//	string strNum = ss.str();
//	int lastIndex = 1;
//	for (size_t i = 0; i < strNum.size(); i++)
//	{
//		if (AToB(lastIndex,strNum[i]-'0'))
//		{
//			lastIndex = strNum[i] - '0';
//		}
//		else
//		{
//			return false;
//		}
//	}
//	return true;
//}

bool IsValid(int iNum)
{
	stringstream ss;
	ss << iNum;
	string strNum = ss.str();
	int lastIndex = 1;
	for (size_t i = 0; i < strNum.size(); i++)
	{
		if (AToB(lastIndex, strNum[i] - '0'))
		{
			lastIndex = strNum[i] - '0';
		}
		else
		{
			return false;
		}
	}
	return true;
}

int main()
{
	ReOpenText();
	int nCase;
	cin >> nCase;
	for (size_t i = 0; i < nCase; i++)
	{
		int iNum;
		cin >> iNum;
		for (size_t i = iNum; i >= 1; i--)
		{
			if (IsValid(i))
			{
				cout << i << endl;
				break;
			}
		}
	}
	return 0;
}

//int main()
//{
//	ReOpenText();
//	int nCase;
//	cin >> nCase;
//	for (size_t i = 0; i < nCase; i++)
//	{
//		int iNum;
//		cin >> iNum;
//		for (size_t i = iNum; i >= 1; i--)
//		{
//			if (IsValid(i))
//			{
//				cout << i << endl;
//				break;
//			}
//		}
//	}
//	return 0;
//}
