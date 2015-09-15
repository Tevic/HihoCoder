#include "../Head.h"

struct Rect
{
	int X1;
	int Y1;
	int X2;
	int Y2;
};

bool hasIntersection(Rect* R1,Rect* R2)
{
	int A1 = max(R1->X1, R2->X1);
	int B1 = min(R1->Y1, R2->Y1);
	int A2 = min(R1->X2, R2->X2);
	int B2 = max(R1->Y2,R2->Y2);
	return !((A1 > A2) || (B1 < B2));
}

int main()
{
	ReOpenText();
	int nCase = 0;
	cin >> nCase;
	for (int i = 0; i < nCase; i++)
	{
		int nCount = 0;
		cin >> nCount;
		vector<Rect*> rectList(nCount,NULL);
		for (int j = 0; j < nCount; j++)
		{
			Rect* rect = new Rect();
			cin >> rect->X1 >> rect->Y1 >> rect->X2 >> rect->Y2;
			rectList[j]=rect;
		}
		int iIntersection = 0;
		for (int m = 0; m < nCount; m++)
		{
			for (int n = m+1; n < nCount; n++)
			{
				int A1 = max(rectList[m]->X1, rectList[n]->X1);
				int B1 = min(rectList[m]->Y1, rectList[n]->Y1);
				int A2 = min(rectList[m]->X2, rectList[n]->X2);
				int B2 = max(rectList[m]->Y2, rectList[n]->Y2);
				if (!((A1 > A2) || (B1 < B2)))
				{
					iIntersection++;
				}
			}
		}
		cout << iIntersection << endl;
	}
}