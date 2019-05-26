class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		
		vector<vector<int>> result;
		
		for (int i = 0; i <= nums.size(); ++ i) {
			vector<bool> visit(nums.size(), false);
			vector<int> current;
			dfs(i, 0, nums, visit, current, result);
		}
		
		return result;
	}
	void dfs(int k, int index, const vector<int> &nums, vector<bool> &visit, vector<int> &current, vector<vector<int>> &result) {
		if (!k) {
			result.push_back(current);
			return ;
		}
		
		for (int i = index; i < nums.size(); ++ i) {
			if (!visit[i]) {
				visit[i] = 1;
				if (!current.size() || i >= current.size()) {
					current.push_back(nums[i]);
					dfs(k - 1, nums, visit, current, result);
					current.pop_back();
				}
				visit[i] = 0;
			}
		}
	}
};