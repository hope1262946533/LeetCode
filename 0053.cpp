class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int len = nums.size();
		if (!len) {
			return 0;
		}
		
		long long result = nums[0], temp = nums[0];
		for (int i = 1; i < len; ++ i) {
			if (temp <= 0) {
				temp = 0;
			}
			temp += nums[i];
			if (temp > result) {
				result = temp;
			}
			
		}
		return (int)result;
	}
};