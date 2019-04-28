//solution 1 
// Time Limit Exceeded
// class Solution {
// public:
	// int jump(vector<int>& nums) {
		// int len = nums.size();
		// vector<int> times(len, len);
		// times[0] = 0;
		// for (int i = 0; i < len; ++ i) {			
			// for (int j = 1; j <= nums[i]; ++ j) {
				// int index = i + j;
				// if (index < len) {
					// times[index] = min(times[index], times[i] + 1);
				// }
			// }
		// }
		// return times[len - 1];
    // }
// };

class Solution {
public:
	int jump(vector<int>& nums) {
		int len = nums.size(), start = 0, new_start = 0, result = 0;
		for (int i = 1; i < len; ++ i) {
			if (new_start + nums[new_start] < i + nums[i]) {
				new_start = i;
			}

			if (i - start == nums[start] || i == len - 1) {
				start = new_start;
				++ result;
			}
		}
		return result;
	}
};