#include "../Head.h"

//void GetNext(string p, vector<int> &next)
//{
//	int pLen = p.size();
//	next[0] = -1;
//	int k = -1;
//	int j = 0;
//	while (j < pLen - 1)
//	{
//		//p[k]��ʾǰ׺��p[j]��ʾ��׺    
//		if (k == -1 || p[j] == p[k])
//		{
//			++j;
//			++k;
//			//��֮ǰnext�����󷨣��Ķ�������4��  
//			if (p[j] != p[k])
//				next[j] = k;   //֮ǰֻ����һ��  
//			else
//				//��Ϊ���ܳ���p[j] = p[ next[j ]]�����Ե�����ʱ��Ҫ�����ݹ飬k = next[k] = next[next[k]]  
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
//			//�����j = -1�����ߵ�ǰ�ַ�ƥ��ɹ�����S[i] == P[j]��������i++��j++      
//			if (j == -1 || strOrg[i] == strPattern[j])
//			{
//				i++;
//				j++;
//			}
//			else
//			{
//				//�����j != -1���ҵ�ǰ�ַ�ƥ��ʧ�ܣ���S[i] != P[j]�������� i ���䣬j = next[j]      
//				//next[j]��Ϊj����Ӧ��nextֵ        
//				j = next[j];
//			}
//			//ͳ��ƥ�����
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