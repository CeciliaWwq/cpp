class Solution {
public:
	string PrintMinNumber(vector<int> numbers) {
		vector<string>str;
		for (int digit : numbers) {
			str.push_back(to_string(digit));
		}
		sort(str.begin(), str.end(), [](string& s1, string& s2) {
			return s1 + s2 < s2 + s1;
			});
		string res = "";
		for (auto& e : str)
		{
			res += e;
		}
		return res;
	}
};