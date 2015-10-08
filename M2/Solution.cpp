#include "../Head.h"
#include "../GlobalFunc.h"

int Query(vector<vector<int>>& graph)
{
	int sum = 0;
	int len = graph.size();
	for (size_t i = 1; i < len; i++)
	{
		for (size_t j = 1; j < len; j++)
		{
			if (graph[i][j] != INT_MAX)
			{
				sum += graph[i][j];
			}
		}
	}
	return sum/2;
}

void Floyd(vector<vector<int>>& graph)
{
	int len = graph.size();

	for (int k = 1; k < len; k++)
	{
		for (int i = 1; i < len; i++)
			for (int j = 1; j<len; j++)
				if (graph[i][k]!=INT_MAX&&graph[k][j]!=INT_MAX&&graph[i][j]>(graph[i][k] + graph[k][j]))
				{
					graph[i][j] = graph[i][k] + graph[k][j];
				}
	}
}


int main()
{
	ReOpenText();
	int N, M;
	cin >> N >> M;
	vector<vector<int>> graph(N + 1, vector<int>(N + 1, INT_MAX));
	for (size_t i = 0; i < N - 1; i++)
	{
		int X, Y, Z;
		cin >> X >> Y >> Z;
		graph[X][Y] = graph[Y][X] = Z;
	}
	for (size_t i = 0; i <= N; i++)
	{
		graph[i][i] = 0;
	}
	Floyd(graph);
	for (size_t i = 0; i < M; i++)
	{
		string op;
		cin >> op;
		if (op == "QUERY")
		{
			cout << Query(graph) << endl;
		}
		else
		{
			int X, Y, Z;
			cin >> X >> Y >> Z;
			graph[X][Y] = graph[Y][X] = Z;
			Floyd(graph);
		}
	}
}