class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		
		sort(nums.begin(), nums.end());//排序是前提
		
		vector<vector<int>> result;
		int len = nums.size(), i = 0;
		while (i < len) {
			int j = i + 1; 
			while (j < len) {
				int two_target = target - nums[i] - nums[j];
				int left = j + 1, right = len - 1;
				while (left < right) {
					int current_sum = nums[left] + nums[right];
					if (current_sum < two_target) {
						++ left;
					} else if (current_sum > two_target) {
						-- right;
					} else {
						vector<int> result_item;
						result_item.push_back(nums[i]);
						result_item.push_back(nums[j]);
						result_item.push_back(nums[left]);
						result_item.push_back(nums[right]);
						result.push_back(result_item);
						
						int current_left = nums[left], current_right = nums[right];
						while (left < right && current_left == nums[left]) {
							++ left;
						}
						while (left < right && current_right == nums[right]) {
							-- right;
						}
					}
				}
				
				int temp = nums[j];
				do {
					++ j;
				} while (j < len && temp == nums[j]);
			}
			int count = upper_bound(nums.begin(), nums.end(), nums[i]) - lower_bound(nums.begin(), nums.end(), nums[i]);
			
			i += count;
		}
		return result;
	}
};
