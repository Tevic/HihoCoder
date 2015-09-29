#include "../Head.h"
#include "../GlobalFunc.h"

//int main()
//{
//	ReOpenText();
//}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NN	1000000
#define MM	100000
#define MOD 1000000007

int n;
int A[NN + 4];
int isfib[MM + 4];
int prevN[MM + 4];
int dp[MM + 4];

void init()
{
	int a = 1, b = 1;
	isfib[0] = isfib[1] = 1;
	int c = a + b;
	while (c <= MM) {
		isfib[c] = 1;
		prevN[c] = b;
		a = b;
		b = c;
		//printf("%d\n", c);
		c = a + b;
	}

	prevN[2] = 1;
	prevN[1] = 0;
}

bool input_and_solve() {
	if (scanf("%d", &n) == EOF)
		return false;

	memset(dp, 0, sizeof dp);

	int a;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		if (a == 1) {
			dp[1] = (dp[1] + dp[0]) % MOD;
			dp[0] = (dp[0] + 1) % MOD;
		}
		else {
			if (isfib[a]) {
				dp[a] = (dp[a] + dp[prevN[a]]) % MOD;
			}
		}
	}

	int ans = 0;
	for (int i = 0; i <= MM; i++) {
		ans = (ans + dp[i]) % MOD;
	}
	printf("%d\n", ans);

	return true;
}


int main()
{
	init();
	while (input_and_solve());
	return 0;
}

