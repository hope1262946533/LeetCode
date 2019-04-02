class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
		int len = nums.size(), index = 0;
		
		if (len < 3) {
			return 0;
		}
		sort(nums.begin(), nums.end());
		
		int result = nums[0] + nums[1] + nums[2];
		int dis = abs_value( result - target);
		
		while (index < len - 2) {
			int two_target = target - nums[index], left = index + 1, right = len - 1;
			while (left < right) {
				int current = nums[left] + nums[right];
					
				if (current < two_target) {
					++ left;
				} else  if (current > two_target) {
					-- right;
				} else {
					int j = nums[left], k = nums[right];
					while (left < right && nums[left] == j) {
						++ left;
					}
					while (left < right && nums[right] == k) {
						-- right;
					}
				}
				
				int temp = abs(current - two_target);
				if (temp < dis) {
					dis = temp;
					result = current + nums[index];
				}
			}
			
			int count = upper_bound(nums.begin(), nums.end(), nums[index]) - lower_bound(nums.begin(), nums.end(), nums[index]);
			index += count;
		}
		return result;
    }
    int abs_value(int x) {
    	return x > 0 ? x : - x;
	}
};
