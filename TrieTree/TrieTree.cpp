#include "..\Head.h"

class TreeNode
{
public:
	char c;
	int count;
	vector<TreeNode*> nodes;
	TreeNode(char c, int count)
	{
		this->c = c;
		this->count = count;
		for (size_t i = 0; i < 26; i++)
		{
			nodes.push_back(NULL);
		}
	};
	~TreeNode();
};



int main()
{
	#pragma warning(disable:4996)
	freopen("Input.txt", "r", stdin);
	vector<TreeNode*> rootList;
	for (size_t i = 0; i < 26; i++)
	{
		TreeNode* root = new TreeNode('a' + i, 0);
		rootList.push_back(root);
	}
	int nCount;
	cin >> nCount;
	for (size_t i = 0; i < nCount; i++)
	{
		string sWord;
		cin >> sWord;
		int treeIndex = sWord[0] - 'a';
		rootList[treeIndex]->count++;
		TreeNode* pre = rootList[treeIndex];
		for (size_t i = 1; i < sWord.size(); i++)
		{
			if (pre->nodes[sWord[i] - 'a'] == NULL)
			{
				TreeNode* node = new TreeNode(sWord[i], 1);
				pre->nodes[sWord[i] - 'a'] = node;
				pre = node;
			}
			else
			{
				pre->nodes[sWord[i] - 'a']->count++;
				pre = pre->nodes[sWord[i] - 'a'];
			}
		}
	}
	int nQuery;
	cin >> nQuery;
	for (size_t i = 0; i < nQuery; i++)
	{
		string sWord;
		cin >> sWord;
		int treeIndex = sWord[0] - 'a';
		TreeNode* pre = rootList[treeIndex];
		int wordCount = pre->count;
		for (size_t i = 1; i < sWord.size(); i++)
		{
			if (pre->nodes[sWord[i] - 'a'] == NULL)
			{
				wordCount = 0;
				break;
			}
			else
			{
				wordCount = pre->nodes[sWord[i] - 'a']->count;
				pre = pre->nodes[sWord[i] - 'a'];
			}
		}
		cout << wordCount << endl;
	}
}
