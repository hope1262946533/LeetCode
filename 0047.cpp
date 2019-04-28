class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		
		set<vector<int>> result_set;
		do {
			result_set.insert(nums);
		} while(next_permutation(nums.begin(), nums.end()));
		
		vector<vector<int>> result;
		result.assign(result_set.begin(), result_set.end());
		return result;
	}
};
