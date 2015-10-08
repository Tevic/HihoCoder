#include "../Head.h"
#include "../GlobalFunc.h"

void GetCnt(int n, int a, int b, int x, int index, int curCnt, int curSum, int& totalCnt)
{
	if (curSum == x)
	{
		if (curCnt == n)
		{
			totalCnt++;
		}
	}
	else if (curSum < x)
	{
		for (int i = index + 1; i <= b; i++)
		{
			GetCnt(n, a, b, x, i, curCnt + 1, curSum + i, totalCnt);
		}
	}
}

int Combination(int n, int m)
{
	const int M = 10007;
	int ans = 1;
	for (int i = n; i >= (n - m + 1); --i)
		ans *= i;
	while (m)
		ans /= m--;
	return ans % M;
}

//int main()
//{
//	//ReOpenText();
//	int n, a, b, x;
//	cin >> n >> a >> b >> x;
//	int totalCnt = 0;
//	GetCnt(n,a,b,x,a-1,0,0,totalCnt);
//	cout << fixed << setprecision(4) <<totalCnt*1.0 / Combination(b-a+1,n) << endl;
//}



long long GetSeq(string& str)
{
	long long facList[] = { 0, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800 };

	int count;
	long long res = 0;
	int len = 12;
	for (int i = 0; i < len; ++i)
	{
		count = 0;
		for (int j = i + 1; j<len; ++j)
			if (str[i]>str[j])
				++count;
		res = res + count*facList[len - i - 1];
	}
	return res;
}

//int main()
//{
//	ReOpenText();
//	int nCase;
//	cin >> nCase;
//	for (size_t i = 0; i < nCase; i++)
//	{
//		string str;
//		cin >> str;
//		cout << GetSeq(str)+1 << endl;
//	}
//}

int is_include(const char *a, const char *b)
{
	if (!a || !b)
		return 0;
	const int iSize = (1 << 16) - 1;
	int hashTable[iSize] = { 0 };
	while (*a)
	{
		if (*a < 0)
		{
			unsigned short key = *((unsigned short*)a);
			++hashTable[key];
			a += 2;
		}
		else
		{
			++hashTable[*a++];
		}
	}
	while (*b)
	{
		if (*b < 0)
		{
			unsigned short key = *((unsigned short*)b);
			--hashTable[key];
			b += 2;
		}
		else
		{
			--hashTable[*b++];
		}
	}
	for (int i = 0; i < iSize; ++i)
	{
		if (hashTable[i] < 0)
			return 0;
	}
	return 1;
}

int main()
{
	ReOpenText();
	char a[1024] = { 0 };
	char b[1024] = { 0 };
	cout << is_include(a, b);
}