#include "..\Head.h"


int N, K;
bool *flag = new bool[K + 1];

bool vote(int **p, bool flag1, int index)
{
	bool result;
	int counter;
	if (flag1 == 1)
	{
		counter = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < K + 1; j++)
			{
				if (p[i][j] == index)
				{
					break;
				}
				if (p[i][j] == index + 1)
				{
					counter++;
					break;
				}
			}
		}
		if (counter < N - counter)
			return true;
		else
			return false;
	}
	else
	{
		counter = 0;
		int pos = 0;
		for (pos = index + 1; pos < K + 1; pos++)
		{
			if (flag[pos] == 1)
			{
				break;
			}
		}
		if (pos == K + 1)
			pos = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < K + 1; j++)
			{
				if (p[i][j] == index)
				{
					break;
				}
				if (p[i][j] == pos)
				{
					counter++;
					break;
				}
			}
		}
		if (counter < N - counter)
			return true;
		else
			return false;
	}
	return result;
}

int main()
{
#ifdef DEBUG_MODE
	freopen("Input.txt", "r", stdin);
#endif // DEBUG_MODE

	cin >> N >> K;
	int **p = new int *[N];
	for (int i = 0; i < K + 1; i++)
		flag[i] = 0;
	for (int i = 0; i < N; i++)
	{
		p[i] = new int[K + 1];
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < K + 1; j++)
			cin >> p[i][j];
	}
	int counter = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < K + 1; j++)
		{
			if (p[i][j] == 0)
			{
				counter++;
				break;
			}
			if (p[i][j] == K)
			{
				break;
			}
		}
	}
	if (counter < N - counter)
		flag[K] = 1;
	else
		flag[K] = 0;
	int k = K - 1;
	while (k >= 1)
	{
		flag[k] = vote(p, flag[k + 1], k);
		k--;
	}
	int i;
	for (i = 0; i < K + 1; i++)
	{
		if (flag[i] == 1)
		{
			cout << i << endl;
			break;
		}
	}
	if (i == K + 1)
		cout << "otaku" << endl;
	return 0;
}
