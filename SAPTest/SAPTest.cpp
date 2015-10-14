#include "../Head.h"
#include "../GlobalFunc.h"



void GetMaxRepeatedLen(string& strIn, int& startIndex, string& strOut)
{
	int len = strIn.size();
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < i; j++)
		{
			string temp;
			int m = i;
			int n = j;
			while (m < len && strIn[m] == strIn[n])
			{
				m++; 
				n++;
			}
			temp = strIn.substr(j, n - j);
			if (temp.size() > strOut.size())
			{
				strOut = temp;
				startIndex = j;
			}
		}
	}
}

int main()
{
	string strIn;
	while (getline(cin, strIn, '\n') && strIn != "")
	{
		string strOut;
		int startIndex = -1;
		GetMaxRepeatedLen(strIn, startIndex, strOut);
		cout << startIndex;
		if (startIndex != -1)
		{
			cout << " " << strOut << endl;
		}
		else
		{
			cout << endl;
		}
	}
	return 0;
}


#define PRECISION 2
#define MAX_VAL 39614081257132168796771975167.0
#define MIN_VAL -39614081257132168796771975167.0


//int main()
//{
//	double N1, N2;
//	char chOp;
//	while (cin>>N1>>chOp>>N2)
//	{
//		if (abs(N1-ceil(N1))<pow(10,-5)&&abs(N2 - ceil(N2))<pow(10, -5))
//		{
//
//		}
//		else
//		{
//			cout << fixed << setprecision(2);
//		}
//		switch (chOp)
//		{
//		case '+':cout << N1 + N2 << endl; break;
//		case '-':cout << N1 - N2 << endl; break;
//		case '*':cout << N1 * N2 << endl; break;
//		case '/':cout << N1 / N2 << endl; break;
//		default:
//			break;
//		}
//	}
//	return 0;
//}