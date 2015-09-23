#include "../Head.h"
#include "../GlobalFunc.h"


int judge(priority_queue<int> &choose, int &heros)
{
	int group = 0;
	while (choose.size() >= 3)
	{
		if (choose.top() == 1)
		{
			group += choose.size() / 6;
			return group;
		}
		else if (choose.size() == 3)
		{
			choose.pop();
			choose.pop();
			int t = choose.top() / 2;
			group += t;
			return group;
		}
		else if (choose.size()>3)
		{
			vector <int> topVal(4);
			topVal[0] = choose.top();
			choose.pop();
			topVal[1] = choose.top();
			choose.pop();
			topVal[2] = choose.top();
			choose.pop();
			topVal[3] = choose.top();
			int t = topVal[2] - topVal[3];
			if (t <= 1)
			{
				for (int i = 0; i < 3; i++)
				{
					topVal[i] --;
					if (topVal[i]>0)
					{
						choose.push(topVal[i]);
					}
				}
				if (choose.size() < 3)
				{
					return group;
				}
				else
				{
					for (int i = 0; i < 3; i++)
					{
						topVal[i] = choose.top();
						choose.pop();
					}
					for (int i = 0; i < 3; i++)
					{
						topVal[i] --;
						if (topVal[i]>0)
						{
							choose.push(topVal[i]);
						}

					}
					group++;
				}
			}
			else
			{
				int add = t / 2;
				group += add;
				for (int i = 0; i < 3; i++)
				{
					topVal[i] -= add * 2;
					if (topVal[i]>0)
					{
						choose.push(topVal[i]);
					}
				}
			}
		}
	}
	return group;
}
int main()
{
	ReOpenText();
	int num;
	cin >> num;

	while (num > 0)
	{
		num--;
		int heros;
		cin >> heros;
		priority_queue<int> choose;
		for (int i = 0; i < heros; i++)
		{
			int t;
			cin >> t;
			choose.push(t);
		}
		cout << judge(choose, heros) << endl;
	}
}
