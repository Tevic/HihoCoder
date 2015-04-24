#include "..\Head.h"



#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isFi(string s)
{
	vector<bool> v(26, false);
	for (int i = 0; i < s.size(); i++)
	{
		v[s[i] - 'a'] = true;
	}
	int count = 0;
	for (int i = 0; i <26; i++)
	{
		if (v[i]) count++;
	}
	if (count == 1 || count == 2 || count == 3 || count == 5 || count == 8 || count == 13 || count == 21) return true;
	else return false;
}



int main()
{
#ifdef DEBUG_MODE
	freopen("Input.txt", "r", stdin);
#endif // DEBUG_MODE
	vector<string> res;
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		for (int j = 1; j <= s.size() - i; j++)
		{
			string temp = s.substr(i, j);
			if (isFi(temp))
			{
				res.push_back(temp);
			}
		}
	}
	std::sort(res.begin(), res.end());
	auto ite = std::unique(res.begin(), res.end());
	if (ite != res.end())
	{
		res.erase(ite, res.end());
	}
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << endl;
	}
	return 0;
}

