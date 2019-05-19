class Solution {
public:
	void sortColors(vector<int>& nums) {
		int zero = 0, current = 0, two = nums.size() - 1;
		while (current <= two) {
			if (nums[current] == 0) {
				swap(nums[current], nums[zero]);
				if (nums[current] == 0) {
					++current;
				}
				++ zero;
			} else if (nums[current] == 1) {
				++ current;
			} else {
				swap(nums[current], nums[two]);
				-- two;
			}
		}
	}
};