#include "../Head.h"
#include "../GlobalFunc.h"

//int main()
//{
//	ReOpenText();
//
//}

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double x0, y0, r;
	cin >> x0 >> y0 >> r;
	long long x, y;
	long long maxX;
	long long maxY;
	double theMax = -1;
	for (x = ceil(x0 - r); x <= floor(x0 + r); x++)
	{
		y = ceil(y0 - sqrt(r * r - (x - x0) *(x - x0)));
		double temp = (x - x0) * (x - x0) + (y - y0) * (y - y0);
		if (temp >= theMax)
		{
			theMax = temp;
			maxX = x;
			maxY = y;
		}


		y = floor(y0 + sqrt(r * r - (x - x0) *(x - x0)));
		temp = (x - x0) * (x - x0) + (y - y0) * (y - y0);
		if (temp >= theMax)
		{
			theMax = temp;
			maxX = x;
			maxY = y;
		}
	}
	cout << maxX << " " << maxY << endl;
}
