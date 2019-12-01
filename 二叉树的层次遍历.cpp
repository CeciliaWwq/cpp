//leetcode102
//https://leetcode-cn.com/problems/binary-tree-level-order-traversal/submissions/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
 class Solution {
 public:
	 vector<vector<int>> levelOrder(TreeNode* root) {
		 queue<TreeNode*> nodeQue;
		 queue<int> levelQue;

		 if (root != nullptr)
		 {
			 nodeQue.push(root);
			 levelQue.push(0);
		 }

		 int curLevel = -1;
		 vector<vector<int>> vv;
		 while (!nodeQue.empty())
		 {
			 TreeNode* node = nodeQue.front();
			 nodeQue.pop();
			 int level = levelQue.front();
			 levelQue.pop();
			 if (level > curLevel)
			 {
				 vv.push_back(vector<int>());
				 curLevel = level;
			 }

			 vv[level].push_back(node->val);
			 if (node->left)
			 {
				 nodeQue.push(node->left);
				 levelQue.push(level + 1);
			 }

			 if (node->right)
			 {
				 nodeQue.push(node->right);
				 levelQue.push(level + 1);
			 }
		 }

		 return vv;
	 }
 };
 */