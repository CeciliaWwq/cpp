//思路：一共可以分成三种情况
//情况一：两个要查找的点分别在根节点的两边，这时候返回根节点即可
//情况二，三：这两个点都在根节点的右边或都在根节点的左边
/*
class Solution {
public:
	Find(TreeNode* root, TreeNode* node)
	{
		if (root = nullptr) { return false; }
		if (root == node) { return root; }
		if (Find(root->left, node))
		{
			return true;
		}
		if (Find(root->right, node))
		{
			return true;
		}
		return false;
	}
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == p || root == q)
			return root;

		bool ispInLeft = Find(root->left, p);
		bool ispInRight = !ispInLeft;
		bool isqInLeft = Find(root->left, q);
		bool isqInRight = !isqInLeft;

		if ((ispInLeft && isqInRight) || (ispInRight && isqInLeft))
		{
			return root;
		}
		else if (isqInLeft && ispInLeft)
		{
			return lowestCommonAncestor(root->left, p, q);
		}
		else
		{
			return lowestCommonAncestor(root->right, p, q);
		}
	}
private:
	typedef struct TreeNode;
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode* root;
};
*/