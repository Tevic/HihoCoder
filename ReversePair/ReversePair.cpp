#include "../Head.h"
#include "../GlobalFunc.h"

void MergeArray(vector<int>& vecList, int start, int mid, int end, long long & totalCount)
{
	int i = start;
	int j = mid+1;
	int m = mid;
	int n = end;
	int k = 0;
	vector<int> vecTmp(end - start + 1);
	while (i<=m&&j<=n)
	{
		if (vecList[i]<=vecList[j])
		{
			vecTmp[k++] = vecList[i++];
		}
		else
		{
			vecTmp[k++] = vecList[j++];
			totalCount += (m-i+1);
		}
	}
	while (i<=m)
	{
		vecTmp[k++] = vecList[i++];
	}
	while (j<=n)
	{
		vecTmp[k++] = vecList[j++];
	}
	for (int i = 0; i < k; i++)
	{
		vecList[start + i] = vecTmp[i];
	}
}

void MergeSort(vector<int>& vecList, int start, int end, long long & totalCount)
{
	if (start<end)
	{
		int mid = start + (end - start) / 2;
		MergeSort(vecList, start, mid, totalCount);
		MergeSort(vecList, mid+1, end, totalCount);
		MergeArray(vecList, start, mid, end, totalCount);
	}
}

int main()
{
	ReOpenText();
	int nCount;
	cin >> nCount;
	vector<int> vecList;
	long long  totalCount=0;
	for (size_t i = 0; i < nCount; i++)
	{
		int fireValue;
		cin >> fireValue;
		vecList.push_back(fireValue);
	}
	MergeSort(vecList, 0, vecList.size()-1, totalCount);
	cout << totalCount << endl;
	return 0;
}