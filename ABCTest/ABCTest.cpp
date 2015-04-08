#include "../Head.h"

int main()
{
	unordered_map<int, char> hmp;
	hmp[5] = 'E';
	hmp[4] = 'D';
	hmp[3] = 'C';
	hmp[1] = 'A';
	hmp[2] = 'B';
	for (auto m:hmp)
	{
		cout << m.first << ' ' << m.second << endl;
	}
}