#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <queue>
#include <map>
#include <hash_map>
using namespace std;

int ballCount[3] = { 0 };

bool MatchDiff(vector<int>& inputDiff)
{
	vector<int> tmpDiff;
	tmpDiff.push_back(abs(ballCount[0] - ballCount[1]));
	tmpDiff.push_back(abs(ballCount[1] - ballCount[2]));
	tmpDiff.push_back(abs(ballCount[0] - ballCount[2]));
	sort(tmpDiff.begin(),tmpDiff.end());
	for (size_t i = 0; i < 3; i++)
	{
		if (tmpDiff[i] != inputDiff[i])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	#pragma warning(disable:4996)
	freopen("Input.txt", "r", stdin);
	vector<int> inputDiff(3);
	for (size_t i = 0; i < 3; i++)
	{
		cin >> inputDiff[i];
	}
	sort(inputDiff.begin(), inputDiff.end());
	int remainBalls = 0;
	int maxBalls = 0;
	string ballSeq;
	cin >> ballSeq;
	for (size_t i = 0; i < ballSeq.size(); i++)
	{
		if (ballSeq[i]=='R')
		{
			ballCount[0]++;
		}
		else if (ballSeq[i] == 'Y')
		{
			ballCount[1]++;
		}
		else
		{
			ballCount[2]++;
		}
		remainBalls++;
		if (remainBalls>maxBalls)
		{
			maxBalls = remainBalls;
		}
		if (MatchDiff(inputDiff))
		{
			remainBalls = 0;
			ballCount[0] = 0;
			ballCount[1] = 0;
			ballCount[2] = 0;
		}
	}
	cout << maxBalls << endl;
	return 0;
}