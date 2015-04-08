#include "../Head.h"


void Up(vector<vector<int> > &board,int &i,int &j,int &bX,int &bY)
{
	int N = board[0].size();
	int M = board.size();
	if (i-1>=0&&board[i-1][j]!=4)
	{
		if (board[i-1][j]==3)
		{
			if (i-2>=0)
			{
				board[i - 2][j] = 3;
				board[i - 1][j] = 1;
				board[i][j] = 0;
				i = i - 1;
				bX = i - 2;
			}
		}
		else
		{
			board[i - 1][j] = 1;
			board[i][j] = 0;
			i = i - 1;
		}
	}
}
void Down(vector<vector<int> > &board, int &i, int &j, int &bX, int &bY)
{
	int N = board[0].size();
	int M = board.size();
	if (i + 1 <M && board[i + 1][j] != 4)
	{
		if (board[i + 1][j] == 3)
		{
			if (i + 2 >= 0)
			{
				board[i + 2][j] = 3;
				board[i + 1][j] = 1;
				board[i][j] = 0;
				i = i + 1;
				bX = i + 1;
			}
		}
		else
		{
			board[i + 1][j] = 1;
			board[i][j] = 0;
			i = i + 1;
		}
	}
}
void Left(vector<vector<int> > &board, int &i, int &j, int &bX, int &bY)
{
	int N = board[0].size();
	int M = board.size();
	if (j - 1 >= 0 && board[i][j - 1] != 4)
	{
		if (board[i][j - 1] == 3)
		{
			if (j - 2 >= 0)
			{
				board[i][j - 2] = 3;
				board[i][j - 1] = 1;
				board[i][j] = 0;
				j = j - 1;
				bY = j - 2;
			}
		}
		else
		{
			board[i][j - 1] = 1;
			board[i][j] = 0;
			j = j - 1;
		}
	}
}
void Right(vector<vector<int> > &board, int &i, int &j, int &bX, int &bY)
{
	int N = board[0].size();
	int M = board.size();
	if (j + 1 < N && board[i][j + 1] != 4)
	{
		if (board[i][j + 1] == 3)
		{
			if (j + 2 >= 0)
			{
				board[i][j + 2] = 3;
				board[i][j + 1] = 1;
				board[i][j] = 0;
				j = j + 1;
				bY = j + 2;
			}
		}
		else
		{
			board[i][j + 1] = 1;
			board[i][j] = 0;
			j = j + 1;
		}
	}
}

int main()
{
	freopen("Input.txt", "r", stdin);
	
	int N, M, S;
	cin >> N >> M >> S;
	vector<vector<int> > board(M,vector<int>(N,0));
	int X, Y;
	int bX, bY;
	int startX, startY;
	int targetX, targetY;
	int boxX, boxY;
	for (size_t i = 0; i < M; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			char val;
			cin >> val;
			board[i][j] = val - '0';
			if (board[i][j]==2)
			{
				targetX = i;
				targetY = j;
			}
			if (board[i][j] == 1)
			{
				startX = i;
				startY = j;
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
		X = startX;
		Y = startY;
		bX = boxX;
		bY = boxY;
		int nStep;
		cin >> nStep;
		for (size_t i = 0; i < nStep; i++)
		{
			bool flag=false;
			char chDirection;
			cin >> chDirection;
			switch (chDirection)
			{
			case 'l':
			{
				if (!flag)
				{
					Left(board, X, Y);
					if (ToDest(board))
					{
						flag = true;
					}
					break;
				}

			}
			case 'r':
			{
				if (!flag)
				{
					Right(board, X, Y);
					if (ToDest(board))
					{
						flag = true;
					}
					break;
				}

			}
			case 'u':
			{
				if (!flag)
				{
					Up(board, X, Y);
					if (ToDest(board))
					{
						flag = true;
					}
					break;
				}

			}
			case 'd':
			{
				if (!flag)
				{
					Down(board, X, Y);
					if (ToDest(board))
					{
						flag = true;
					}
					break;
				}

			}
			default:
				break;
			}
		}

		if (ToDest(board))
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
		for (size_t i = 0; i < M; i++)
		{
			for (size_t j = 0; j < N; j++)
			{
				if (board[i][j]!=4)
				{
					board[i][j] = 0;
				}
			}
		}
		board[startX][startY] = 1;
		board[boxX][boxY] = 3;
	}
	return 0;
}