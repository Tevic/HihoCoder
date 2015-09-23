#include "../Head.h"
#include "../GlobalFunc.h"

void genWeight(vector<int> &w, int n, int u, int v)
{
	vector<string> vs;
	if (n == 1) {
		vs = { "." };	//1
	}
	else if (n == 2) {
		vs = { ".", "-" };		//2
	}
	else if (n == 3) {
		vs = { "..", ".-", "-" };		//3
	}
	else if (n == 4) {
		vs = { "..", ".-", "-.", "--" };		//4
	}
	else if (n == 5) {
		vs = { "...", "..-", ".-.", ".--", "-" };		//5
	}
	else if (n == 6) {
		vs = { "...", "..-", ".-.", ".--", "-.", "--" };			//6
	}
	else if (n == 7) {
		vs = { "...", "..-", ".-.", ".--", "-..", "-.-", "--" };			//7
	}
	else if (n == 8) {
		vs = { "...", "..-", ".-.", ".--", "-..", "-.-", "--.", "---" };		//8

	}
	else if (n == 9) {
		vs = { "....", "...-", "..-.", "..--", ".-..", ".-.-", ".--.", ".---", "-" };		//9
	}
	else if (n == 10) {
		vs = { "....", "...-", "..-.", "..--", ".-..", ".-.-", ".--.", ".---", "-.", "--" };		//10
	}
	else if (n == 11) {
		vs = { "....", "...-", "..-.", "..--", ".-..", ".-.-", ".--.", ".---", "-..", "-.-", "--." };		//11
	}
	else if (n == 12) {
		vs = { "....", "...-", "..-.", "..--", ".-..", ".-.-", ".--.", ".---", "-..", "-.-", "--.", "---" };		//12
	}
	else if (n == 13) {
		vs = { "....", "...-", "..-.", "..--", ".-..", ".-.-", ".--.", ".---", "-...", "-..-", "-.-.", "-.--", "--" };		//13
	}
	else if (n == 14) {
		vs = { "....", "...-", "..-.", "..--", ".-..", ".-.-", ".--.", ".---", "-...", "-..-", "-.-.", "-.--", "--.", "---" };		//14
	}
	else if (n == 15) {
		vs = { "....", "...-", "..-.", "..--", ".-..", ".-.-", ".--.", ".---", "-...", "-..-", "-.-.", "-.--", "--..", "--.-", "---." };		//15
	}
	for (int i = 0; i < vs.size(); i++) {
		int t = 0;
		for (int j = 0; j < vs[i].size(); j++) {
			if (vs[i][j] == '.') {
				t += u;
			}
			else {
				t += v;
			}
		}
		w.push_back(t);
	}
}


int main()
{
	ReOpenText();
	int T, u, v;
	char str[100001];
	int mark[256];

	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d%d", &u, &v);
		scanf("%s", str);

		for (int i = '0'; i <= '9'; i++) {
			mark[i] = 0;
		}
		for (int i = 'a'; i <= 'e'; i++) {
			mark[i] = 0;
		}
		for (int i = 0; str[i] != '\0'; i++) {
			mark[str[i]]++;
		}
		vector<int> vec;
		for (int i = '0'; i <= '9'; i++) {
			if (mark[i] != 0) {
				vec.push_back(mark[i]);
			}
		}
		for (int i = 'a'; i <= 'e'; i++) {
			if (mark[i] != 0) {
				vec.push_back(mark[i]);
			}
		}

		sort(vec.begin(), vec.end());
		reverse(vec.begin(), vec.end());
		vector<int> w;
		genWeight(w, vec.size(), u, v);
		sort(w.begin(), w.end());
		int len = 0;
		for (int i = 0; i < vec.size(); i++) {
			len += vec[i] * w[i];
		}
		printf("%d\n", len);
	}

	return 0;
}
