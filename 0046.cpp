//solution 1
// class Solution {
// public:
	// vector<vector<int>> permute(vector<int>& nums) {
		// sort(nums.begin(), nums.end());
		
		// vector<vector<int>> result;
		// do {
			// result.push_back(nums);
		// } while(next_permutation(nums.begin(), nums.end()));
		// return result;
	// }
// };

//solution 2
class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<int> current;
		vector<bool> visit(nums.size(), false);
		vector<vector<int>> result;
		permutation(nums, current, visit, result);
		return result;
	}
	
	void permutation(const vector<int> & nums, vector<int> &current, vector<bool> &visit, vector<vector<int>> &result) {
		if (current.size() == nums.size()) {
			result.push_back(current);
			return ;
		}
		
		for (int i = 0; i < nums.size(); ++ i) {
			if (!visit[i]) {
				current.push_back(nums[i]);
				visit[i] = true;
				permutation(nums, current, visit, result);
				
				current.pop_back();
				visit[i] = false;
			}
		}
	}
};