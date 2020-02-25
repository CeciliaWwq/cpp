#if 0
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		bool result = false;
		if (pRoot1 != NULL && pRoot2 != NULL) {
			if (pRoot1->val == pRoot2->val) {
				result = isSubTree(pRoot1, pRoot2);
			}
			if (!result) {
				result = isSubTree(pRoot1->left, pRoot2);
			}
			if (!result)
			{
				result = isSubTree(pRoot1->right, pRoot2);
			}
		}
		return result;
	}
	bool isSubTree(TreeNode* pR1, TreeNode* pR2)
	{
		if (pR2 == NULL)
		{
			return true;
		}
		if (pR1 == NULL)
		{
			return false;
		}
		if (pR1->val != pR2->val)
		{
			return false;
		}
		return isSubTree(pR1->left, pR2->left) && isSubTree(pR1->right, pR2->right);
	}
};
#endif