#include "../Head.h"

struct TreeNode
{
	char value;
	TreeNode* left;
	TreeNode* right;
	TreeNode(char val):value(val),left(NULL),right(NULL) {};
};

TreeNode* BuildTree(string& strPreOrder,string& strInOrder,int pStart,int pEnd,int iStart,int iEnd)
{
	if (pEnd>=pStart)
	{
		TreeNode* root = new TreeNode(strPreOrder[pStart]);
		int index = -1;
		for (int i = iStart; i <= iEnd; i++)
		{
			if (strPreOrder[pStart]==strInOrder[i])
			{
				index = i;
				break;
			}
		}
		root->left = BuildTree(strPreOrder, strInOrder, pStart+1, index-iStart+pStart, iStart, index-1);
		root->right = BuildTree(strPreOrder, strInOrder, pEnd-iEnd+index+1, pEnd, index+1, iEnd);
		return root;
	}
	else
	{
		return NULL;
	}
}

void PostOrderTraverse(TreeNode* root,string& seq)
{
	if (root)
	{
		PostOrderTraverse(root->left, seq);
		PostOrderTraverse(root->right, seq);
		seq.push_back(root->value);
	}
}

int main()
{
	ReOpenText();
	string strPreOrder;
	string strInOrder;
	cin >> strPreOrder>>strInOrder;
	TreeNode* root = BuildTree(strPreOrder, strInOrder, 0, strPreOrder.size()-1, 0,strInOrder.size()-1);
	string postSeq;
	PostOrderTraverse(root,postSeq);
	cout << postSeq << endl;
	return 0;
}
