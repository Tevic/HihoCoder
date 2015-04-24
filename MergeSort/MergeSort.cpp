#include "../Head.h"

void MergeArray(vector<int>& arr, int start, int mid, int end)
{
	int i = start;
	int j = mid + 1;
	int m = mid;
	int n = end;
	int k = 0;
	int* tmp = new int[end - start + 1];
	while (i <= m&&j <= n)
	{
		if (arr[i]<arr[j])
			tmp[k++] = arr[i++];
		else
			tmp[k++] = arr[j++];
	}
	while (i <= m)
		tmp[k++] = arr[i++];
	while (j <= n)
		tmp[k++] = arr[j++];
	for (int i = 0; i< end - start + 1; i++)
	{
		arr[start + i] = tmp[i];
	}
	delete[] tmp;
}

void MergeSort(vector<int>& arr, int left, int right)
{
	if (left<right)
	{
		int mid = (left + right) / 2;
		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);
		MergeArray(arr, left, mid, right);
	}
}




int main(int argc, char* argv[])
{
	vector<int> arr = { 5, 4, 3, 2, 1, 8 };
	MergeSort(arr, 0, 5);
	for (int i = 0; i<6; i++)
	{
		cout << arr[i] << " ";
	}

	return 0;
}