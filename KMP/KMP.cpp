#include "../Head.h"

//void GetNext(string p, vector<int> &next)
//{
//	int pLen = p.size();
//	next[0] = -1;
//	int k = -1;
//	int j = 0;
//	while (j < pLen - 1)
//	{
//		//p[k]表示前缀，p[j]表示后缀    
//		if (k == -1 || p[j] == p[k])
//		{
//			++j;
//			++k;
//			//较之前next数组求法，改动在下面4行  
//			if (p[j] != p[k])
//				next[j] = k;   //之前只有这一行  
//			else
//				//因为不能出现p[j] = p[ next[j ]]，所以当出现时需要继续递归，k = next[k] = next[next[k]]  
//				next[j] = next[k];
//		}
//		else
//		{
//			k = next[k];
//		}
//	}
//}
//
//int main()
//{
//	#ifdef DEBUG_MODE
//	freopen("Input.txt", "r", stdin);
//	#endif // DEBUG_MODE
//	int nQuery;
//	cin >> nQuery;
//	for (size_t k = 0; k < nQuery; k++)
//	{
//		string strPattern;
//		string strOrg;
//		cin >> strPattern >> strOrg;
//
//		int i = 0;
//		int j = 0;
//		int sLen = strOrg.size();
//		int pLen = strPattern.size();
//		vector<int> next(pLen+1, 0);
//		GetNext(strPattern, next);
//		int count = 0;
//		while (i < sLen && j < pLen)
//		{
//			//①如果j = -1，或者当前字符匹配成功（即S[i] == P[j]），都令i++，j++      
//			if (j == -1 || strOrg[i] == strPattern[j])
//			{
//				i++;
//				j++;
//			}
//			else
//			{
//				//②如果j != -1，且当前字符匹配失败（即S[i] != P[j]），则令 i 不变，j = next[j]      
//				//next[j]即为j所对应的next值        
//				j = next[j];
//			}
//			//统计匹配次数
//			if (j == pLen)
//			{
//				count++;
//				j = next[j];
//				i = i - pLen + 2;
//			}
//		}
//		cout << count << endl;
//	}
//}

int KMP(string t, string p){
	int n = p.size();
	vector <int> next(n + 1, 0);
	for (int i = 1; i<n; i++){
		int j = i;
		while (j > 0){
			j = next[j];
			if (p[j] == p[i]){
				next[i + 1] = j + 1;
				break;
			}
		}
	}

	int ans = 0;
	int m = t.size();
	for (int i = 0, j = 0; i<m; i++){
		if (j < n && t[i] == p[j])  j++;
		else{
			while (j > 0){
				j = next[j];
				if (t[i] == p[j]){
					j++;
					break;
				}
			}
		}
		if (j == n)  ans++;
	}
	return ans;
}

int main(){
	#ifdef DEBUG_MODE
	freopen("Input.txt", "r", stdin);
	#endif // DEBUG_MODE
	string t, p;
	int n;
	scanf("%d", &n);
	while (n--){
		cin >> p >> t;
		cout << KMP(t, p) << endl;
	}
	return 0;
}