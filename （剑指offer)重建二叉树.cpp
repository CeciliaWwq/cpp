#include<iostream>
#include<vector>
using namespace std;
//Definition for binary tree
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		if (vin.size() == 0)
		{
			return 0;
		}
		TreeNode *ReTree = new TreeNode(pre[0]);
		int midnum = 0;//寻找中序中根节点之前的结点个数
		for (; midnum < vin.size(); midnum++)
		{
			if (pre[0] == vin[midnum])
			{
				break;
			}
		}
		vector<int>newLpre;
		newLpre.resize(midnum);
		vector<int>newLvin;
		newLvin.resize(midnum);
		for (int i = 0; i < midnum; i++)
		{
			newLpre[i] = pre[i + 1];
		}
		for (int j = 0; j < midnum; j++)
		{
			newLvin[j] = vin[j];
		}
		ReTree->left = reConstructBinaryTree(newLpre, newLvin);
		vector<int>newRpre;
		newRpre.resize(pre.size() - 1 - midnum);
		vector<int>newRvin;
		newRvin.resize(vin.size() - 1 - midnum);
		for (int i = 0; i < pre.size() - 1 - midnum; i++)
		{
			newRpre[i] = pre[i + 1];
		}
		for (int j = 0; j < vin.size() - 1 - midnum; j++)
		{
			newRvin[j] = vin[j];
		}
		ReTree->right = reConstructBinaryTree(newRpre, newRvin);
		return ReTree;
	}
	
};

