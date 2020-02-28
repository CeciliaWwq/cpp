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
	void Mirror(TreeNode* pRoot) {
		TreeNode* temp = NULL;
		if (pRoot != NULL)
		{
			temp = pRoot->right;
			pRoot->right = pRoot->left;
			pRoot->left = temp;
			if (pRoot->left != NULL)
				Mirror(pRoot->left);
			if (pRoot->right != NULL)
				Mirror(pRoot->right);
		}
	}
};
#endif