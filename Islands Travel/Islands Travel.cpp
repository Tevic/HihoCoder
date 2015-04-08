#include "..\Head.h"

struct Point
{
	int X;
	int Y;
};

int main()
{
	#pragma warning(disable:4996)
	freopen("Input.txt", "r", stdin);
	const int MAX_VALUE = 2147483647;
	int N;
	int X, Y;
	cin >> N;
	vector<Point*> vPoints;
	vector<int> bVisited(N);
	vector<int> dist(N);
	vector<vector<int> > graph(N, vector<int>(N));
	for (size_t i = 0; i < N; i++)
	{
		Point* pt=new Point();
		cin >> pt->X;
		cin >> pt->Y;
		vPoints.push_back(pt);
	}
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			if (i==j)
			{
				graph[i][j] = 0;
			}
			else
			{
				int v1 = abs(vPoints[i]->X - vPoints[j]->X);
				int v2 = abs(vPoints[i]->Y - vPoints[j]->Y);
				graph[i][j] = v1<v2?v1:v2;
			}
		}
	}
	for (size_t i = 0; i < N; i++)
	{
		delete vPoints[i];
	}

	bVisited[0] = 1;
	for (int i = 0; i < N; i++){
		dist[i] = graph[0][i];
	}

	int index;
	for (int i = 1; i < N; i++){
		int mincost = MAX_VALUE;
		for (int j = 0; j < N; j++){
			if (!bVisited[j] && dist[j] < mincost){
				mincost = dist[j];
				index = j;
			}
		}
		bVisited[index] = 1;
		for (int j = 0; j < N; j++){
			if (!bVisited[j] && dist[j] > dist[index] + graph[index][j]){
				dist[j] = dist[index] + graph[index][j];
			}
		}
	}
	cout << dist[N - 1] << endl;
	return 0;
}