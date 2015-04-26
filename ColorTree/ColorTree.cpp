#include "../Head.h"

bool DFS(vector<vector<int> > &vTree, vector<int> &vColor, vector<bool> &vVisited, int iNode)
{
	if (vVisited[iNode])
	{
		return false;
	}
	vVisited[iNode] = true;
	for (size_t i = 1; i < vTree.size(); i++)
	{
		if (!vVisited[i] && (vTree[i][iNode] != -1))
		{
			DFS(vTree, vColor, vVisited, i);
		}
	}
	return true;
}

void Op1(vector<vector<int> > &vTree, vector<int> &vColor)
{
	int nNodes = vTree.size()-1;
	vector<bool> vVisited(nNodes+1,false);
	int nSubTrees = 0;
	for (size_t i = 1; i < nNodes+1; i++)
	{
		if (DFS(vTree, vColor, vVisited, i))
		{
			nSubTrees++;
		}
	}
	cout << nSubTrees << endl;
}



void Op2(vector<vector<int> > &vTree,vector<int> &vColor, int iNode, int iColor)
{
	vColor[iNode] = iColor;
	int nNodes = vTree.size() - 1;
	for (size_t i = 1; i < nNodes+1; i++)
	{
		if (vTree[iNode][i]!=-1&&vColor[i]!=vColor[iNode])
		{
			vTree[iNode][i] = -1;
			vTree[i][iNode] = -1;
		}
	}
}

int main()
{
	ReOpenText();
	int nCase;
	cin >> nCase;
	for (size_t i = 0; i < nCase; i++)
	{
		cout << "Case #" << i+1 << ":" << endl;
		int nNodes;
		cin >> nNodes;
		vector<vector<int> > vTree(nNodes + 1, vector<int>(nNodes + 1, -1));
		vector<int> vColor(nNodes + 1, 0);
		for (size_t i = 0; i < nNodes-1; i++)
		{
			int m,n;
			cin >> m >> n;
			vTree[m][n] = 1;
			vTree[n][m] = 1;
		}
		int nOps;
		cin >> nOps;
		for (size_t i = 0; i < nOps; i++)
		{
			int iOpeType;
			cin >> iOpeType;
			switch (iOpeType)
			{
				case 1:
				{
					Op1(vTree, vColor);
					break;
				}
				case 2:
				{
					int iNode, iColor;
					cin >> iNode >> iColor;
					Op2(vTree,vColor, iNode, iColor);
					break;
				}
				default:
					break;
			}
		}
	}
}