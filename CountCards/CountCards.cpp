#include "../Head.h"
#include "../GlobalFunc.h"

unsigned long long MAX_VALUE = 2 ^ 64;
unsigned long long SUM = 0;


int GetCardValue(char chCard)
{
	switch (chCard)
	{
	case 'A': return 1;
	case 'T': return 10;
	case 'J': return 11;
	case 'Q': return 12;
	case 'K': return 13;
	default:  return chCard-'0';
	}
}

unsigned long long GetAllCardsPrem(vector<int> nCardsNum, int curCard ,unsigned long long curNum)
{
	curNum = curNum * nCardsNum[curCard];
	nCardsNum[curCard] -- ;
	bool hasDiffCards=false;
	int sumTotal = 0;
	for (size_t i = 1; i < nCardsNum.size(); i++)
	{
		sumTotal += nCardsNum[i];
		if (nCardsNum[i] != 0 && curCard!=i)
		{
			hasDiffCards = true;
			curNum = GetAllCardsPrem(nCardsNum, i, curNum);
		}
	}
	if (!hasDiffCards)
	{
		if (sumTotal==0)
		{
			SUM += curNum;
		}
		else
		{
			return 0;
		}
	}
	return curNum;
}

int main()
{
	ReOpenText();
	int nCase;
	scanf("%d",&nCase);
	for (size_t i = 0; i < nCase; i++)
	{
		SUM = 0;
		printf("Case #%d: ", i + 1);
		vector<int> nCardsNum(14, 0);
		int nCards;
		scanf("%d", &nCards);
		for (size_t i = 0; i < nCards; i++)
		{
			string sCard;
			cin >> sCard;
			nCardsNum[GetCardValue(sCard[0])]++;
		}
		for (size_t j = 1; j <= 13; j++)
		{
			if (nCardsNum[j] != 0)
			{
				GetAllCardsPrem(nCardsNum, j, 1);
			}
		}
		cout << SUM << endl;
	}
	return 0;
}