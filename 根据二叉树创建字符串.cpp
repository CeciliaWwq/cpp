/*
class Solution {
public:
	void _tree2str(TreeNode* t, string& str) {
		if (t == nullptr)
			return;

		str += to_string(t->val);
		if (t->left != nullptr || t->right != nullptr)
		{
			str += '(';
			_tree2str(t->left, str);
			str += ')';
		}

		if (t->right != nullptr)
		{
			str += '(';
			_tree2str(t->right, str);
			str += ')';
		}
	}

	string tree2str(TreeNode* t) {
		string str;
		_tree2str(t, str);
		return str;
	}
};
*/