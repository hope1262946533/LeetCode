class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		set<vector<int>> result_set;
		
		for (int i = 0; i <= nums.size(); ++ i) {
			vector<int> current;
			dfs(nums, 0, i, current, result_set);
		}
		vector<vector<int>> result;
        result.assign(result_set.begin(), result_set.end());
		return result;
	}
	void dfs(const vector<int>& nums, int current_index, int count, vector<int> &current, set<vector<int>>& result) {
		if (!count) {
			result.insert(current);
			return;
		}
		if (current_index >= nums.size()) {
			return;
		}
		
		dfs(nums, current_index + 1, count, current, result);
		
		current.push_back(nums[current_index]);
		dfs(nums, current_index + 1, count - 1, current, result);
		current.pop_back();
	}
};