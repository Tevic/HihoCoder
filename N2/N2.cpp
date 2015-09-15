#include "../Head.h"

#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

string Decompress(string temp)
{
	int i = 0;
	stack<int> tempPos;
	int tempRe = 0;
	int flag = 0;
	string tempString;
	for (i = 0; i < temp.length(); i++)
	{
		if ((int)(temp[i]) >= 65 && (int)(temp[i]) <= 90)
		{
			tempString += temp.substr(i, 1);
		}
		if ((int)(temp[i]) <= 57 && (int)(temp[i]) >= 49)
		{
			if (temp[i - 1] != ')')
			{
				//for (int j = 0; j < (int)(temp[i]) - 49; j++)
				//	tempString += temp.substr(i - 1, 1);
				tempRe = (int)(temp[i]) - 48;
				flag = i - 1;
			}
			while ((int)(temp[i + 1]) <= 57 && (int)(temp[i + 1]) >= 48)
			{
				i++;
				tempRe = tempRe * 10 + (int)(temp[i]) - 48;
			}
			for (int j = 0; j < tempRe - 1; j++)
			{
				tempString += temp.substr(flag, 1);
			}
		}
		if ((int)temp[i] == 40)
		{
			int flag = i;
			string tempString2;
			tempPos.push(i);
			while (!tempPos.empty())
			{
				i++;
				if ((int)temp[i] == 40)
					tempPos.push(i);
				if ((int)temp[i] == 41)
					tempPos.pop();
			}
			if ((int)(temp[i + 1]) <= 57 && (int)(temp[i + 1]) >= 49)
			{
				tempString2 = Decompress(temp.substr(flag + 1, i - 1 - flag));
				tempRe = (int)(temp[i + 1]) - 48;
				i++;
				while ((int)(temp[i + 1]) <= 57 && (int)(temp[i + 1]) >= 48)
				{
					i++;
					tempRe = tempRe * 10 + (int)(temp[i]) - 48;
				}
				for (int j = 0; j <= tempRe - 1; j++)
					tempString += tempString2;
				//if (i < temp.length() - 1)
				//	i++;
			}
		}
	}
	//	cout << tempString << endl;
	return tempString;
}
int main()
{
	ReOpenText();
	int n;
	cin >> n;
	while (n > 0)
	{
		string temp;
		string tempString;
		cin >> temp;
		tempString = Decompress(temp);
		//		cout << tempString << endl;
		cout << tempString.length() << endl;
		//		cout << (int)temp[0] << endl;
		n--;
	}
	return 0;
}