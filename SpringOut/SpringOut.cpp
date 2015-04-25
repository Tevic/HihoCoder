#include "..\Head.h"

bool HasPreferThanASuccess(vector<vector<int> >& vPreferList, int iPeople, int A, vector<bool>& vSuccessList)
{
	for (size_t i = 0; i < vPreferList[0].size(); i++)
	{
		if (vPreferList[iPeople][i] == A)
		{
			return false;
		}
		if ((vPreferList[iPeople][i]>A && vSuccessList[vPreferList[iPeople][i] - 1]) || vPreferList[iPeople][i] == 0)
		{
			return true;
		}
	}
}

void Vote(vector<vector<int> >& vPreferList, vector<bool>& vSuccessList)
{
	int nPeople = vPreferList.size();
	int nCandidate = vPreferList[0].size()-1;
	for (size_t i = nCandidate; i >= 1; i--)
	{
		int nCountAgree = 0;
		for (size_t j = 0; j < nPeople; j++)
		{
			if (!HasPreferThanASuccess(vPreferList, j, i, vSuccessList))
			{
				nCountAgree++;
			}
		}
		if (nCountAgree>(nPeople/2))
		{
			vSuccessList[nCandidate - 1] = true;
		}
		else
		{
			vSuccessList[nCandidate - 1] = false;
		}
	}
}

int main()
{
	ReOpenText();
	int nPeople;
	int nCandidate;
	cin >> nPeople >> nCandidate;
	vector<vector<int> > vPreferList(nPeople, vector<int>(nCandidate + 1));
	vector<bool> vSuccessList(nCandidate + 1);
	vSuccessList[nCandidate] = true;
	for (size_t i = 0; i < nPeople; i++)
	{
		for (size_t j = 0; j < nCandidate+1; j++)
		{
			cin>>vPreferList[i][j];
		}
	}
	Vote(vPreferList, vSuccessList);
	bool iSelected=0;
	for (size_t i = 0; i < vSuccessList.size()-1; i++)
	{
		if (vSuccessList[i])
		{
			iSelected = i + 1;
			break;
		}
	}
	if (iSelected!=0)
	{
		cout << iSelected << endl;
	}
	else
	{
		cout << "otaku" << endl;
	}
	return 0;
}

//int N, K;
//bool *flag = new bool[K + 1];
//
//bool vote(int **p, bool flag1, int index)
//{
//	bool result;
//	int counter;
//	if (flag1 == 1)
//	{
//		counter = 0;
//		for (int i = 0; i < N; i++)
//		{
//			for (int j = 0; j < K + 1; j++)
//			{
//				if (p[i][j] == index)
//				{
//					break;
//				}
//				if (p[i][j] == index + 1)
//				{
//					counter++;
//					break;
//				}
//			}
//		}
//		if (counter < N - counter)
//			return true;
//		else
//			return false;
//	}
//	else
//	{
//		counter = 0;
//		int pos = 0;
//		for (pos = index + 1; pos < K + 1; pos++)
//		{
//			if (flag[pos] == 1)
//			{
//				break;
//			}
//		}
//		if (pos == K + 1)
//			pos = 0;
//		for (int i = 0; i < N; i++)
//		{
//			for (int j = 0; j < K + 1; j++)
//			{
//				if (p[i][j] == index)
//				{
//					break;
//				}
//				if (p[i][j] == pos)
//				{
//					counter++;
//					break;
//				}
//			}
//		}
//		if (counter < N - counter)
//			return true;
//		else
//			return false;
//	}
//	return result;
//}
//
//int main()
//{
//	ReOpenText();
//	cin >> N >> K;
//	int **p = new int *[N];
//	for (int i = 0; i < K + 1; i++)
//		flag[i] = 0;
//	for (int i = 0; i < N; i++)
//	{
//		p[i] = new int[K + 1];
//	}
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < K + 1; j++)
//			cin >> p[i][j];
//	}
//	int counter = 0;
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < K + 1; j++)
//		{
//			if (p[i][j] == 0)
//			{
//				counter++;
//				break;
//			}
//			if (p[i][j] == K)
//			{
//				break;
//			}
//		}
//	}
//	if (counter < N - counter)
//		flag[K] = 1;
//	else
//		flag[K] = 0;
//	int k = K - 1;
//	while (k >= 1)
//	{
//		flag[k] = vote(p, flag[k + 1], k);
//		k--;
//	}
//	int i;
//	for (i = 0; i < K + 1; i++)
//	{
//		if (flag[i] == 1)
//		{
//			cout << i << endl;
//			break;
//		}
//	}
//	if (i == K + 1)
//		cout << "otaku" << endl;
//	return 0;
//}
