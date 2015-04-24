#pragma warning(disable:4996)

#define DEBUG_MODE
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <queue>
#include <map>
#include <unordered_map>
#include <sstream>

using namespace std;

void ReOpenText()
{
	#ifdef DEBUG_MODE
	freopen("Input.txt", "r", stdin);
	#endif // DEBUG_MODE
}


