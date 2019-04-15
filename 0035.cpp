class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		if (!nums.size()) {
			return 0;
		}
		return find_larger(nums, target);
	}
	int find_larger(const vector<int>& nums, int target) {
		int left = 0, right = nums.size() - 1, mid;
		while (left <= right) {
			mid = (left + right) >>= 1;
			if (nums[mid] == target) {
				return mid;
			} else if (nums[mid] > target) {
				right = mid - 1;
			} else {
				left = mid + 1;
			}
		}
		return left;
	}
};