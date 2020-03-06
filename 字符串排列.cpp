class Solution {
public:
	vector<string> Permutation(string str) {
		if (str.size() != 0) {
			int nSize = str.size();
			Permutation(str, nSize, 0);
		}
		for (set<string>::iterator iter = permutationSet.begin(); iter != permutationSet.end(); ++iter)
		{
			permutation.push_back(*iter);
		}
		return permutation;
	}
	void Permutation(string str, int nSize, size_t n)
	{
		if (n == str.size()) {
			permutationSet.insert(str);
		}
		else {
			Permutation(str, nSize, n + 1);
			for (int i = n + 1; i < str.size(); ++i)
			{
				if (str[n] != str[i])
				{
					char tmp = str[n];
					str[n] = str[i];
					str[i] = tmp;
					Permutation(str, nSize, n + 1);
					tmp = str[n];
					str[n] = str[i];
					str[i] = tmp;
				}
			}
		}
	}
public:
	vector<string> permutation;
	set<string> permutationSet;
};