class Solution {
public:
	bool canJump(vector<int>& nums) {
		int start = 0, new_start = 0, len = nums.size();
        if (!nums[start]) {
			return start == len - 1;;
		}
		for (int i = 1; i < len; ++ i) {
			if (new_start + nums[new_start] <= i + nums[i]) {
				new_start = i;
			}
			
			if (start + nums[start] == i || i == len - 1) {
				start = new_start;
				if (nums[start] == 0) {
					return i == len - 1;
				}
			}
		}
		return true;
	}
};