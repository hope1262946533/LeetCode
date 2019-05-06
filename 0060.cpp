class Solution {
public:
	string getPermutation(int n, int k) {
		vector<int> num;
		for (int i = 0; i < n; ++ i) {
			num.push_back(i + 1);
		}
		while (-- k) {
			next_permutation(num.begin(), num.end());
		}
		string result;
		for (int i = 0; i < n; ++ i) {
			result.push_back('0' + num[i]);
		}
		return result;
	}
};