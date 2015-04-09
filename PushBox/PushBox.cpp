#include "../Head.h"


void Move(vector<vector<int> > &board, char chDirection, int &pX, int &pY, int &bX, int &bY)
{
	int N = board[0].size();
	int M = board.size();
	switch (chDirection)
	{
	case 'l':
	{
		if (pY - 1 >= 0 && board[pX][pY - 1] != 4)
		{
			if (pY - 1 == bY&&pX == bX)
			{
				if (bY - 1 >= 0 && board[bX][bY - 1] != 4)
				{
					bY--;
					pY--;
				}
			}
			else
			{
				pY--;
			}
		}
		break;
	}
	case 'r':
	{
		if (pY + 1 < N && board[pX][pY + 1] != 4)
		{
			if (pY + 1 == bY&&pX == bX)
			{
				if (bY + 1 < N&&board[bX][bY + 1] != 4)
				{
					bY++;
					pY++;
				}
			}
			else
			{
				pY++;
			}
		}
		break;
	}
	case 'u':
	{
		if (pX - 1 >= 0 && board[pX - 1][pY] != 4)
		{
			if (pX - 1 == bX&&pY == bY)
			{
				if (bX - 1 >= 0 && board[bX - 1][bY] != 4)
				{
					bX--;
					pX--;
				}
			}
			else
			{
				pX--;
			}
		}
		break;
	}
	case 'd':
	{
		if (pX + 1 < M && board[pX + 1][pY] != 4)
		{
			if (pX + 1 == bX&&pY == bY)
			{
				if (bX + 1 >= 0 && board[bX + 1][bY] != 4)
				{
					bX++;
					pX++;
				}
			}
			else
			{
				pX++;
			}
		}
		break;
	}
	default:
		break;
	}
}


int main()
{
	freopen("Input.txt", "r", stdin);

	int N, M, S;
	cin >> N >> M >> S;
	vector<vector<int> > board(M, vector<int>(N, 0));
	int peopleX, peopleY;
	int targetX, targetY;
	int boxX, boxY;
	for (size_t i = 0; i < M; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			char val;
			cin >> val;
			board[i][j] = val - '0';
			if (board[i][j] == 2)
			{
				targetX = i;
				targetY = j;
			}
			if (board[i][j] == 1)
			{
				peopleX = i;
				peopleY = j;
			}
			if (board[i][j] == 3)
			{
				boxX = i;
				boxY = j;
			}
		}
	}

	for (size_t i = 0; i < S; i++)
	{
		int pX = peopleX;
		int pY = peopleY;
		int bX = boxX;
		int bY = boxY;
		int nStep;
		cin >> nStep;
		bool bToDest = false;
		for (size_t i = 0; i < nStep; i++)
		{
			char chDirection;
			cin >> chDirection;
			Move(board, chDirection, pX, pY, bX, bY);
			if (bX==targetX&&bY==targetY)
			{
				bToDest = true;
			}
		}

		if (bToDest)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	return 0;
}