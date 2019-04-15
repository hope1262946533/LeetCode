class Solution {
public:
	int search(vector<int>& nums, int target) {
		if (!nums.size()) {
			return -1;
		}
		int left = 0, right = nums.size() - 1;
		while (left <= right) {
			int mid = (left + right) >> 1;
			
			if (nums[mid] == target) {
				return mid;
			} else if (nums[mid] < target) {
				if (nums[left] <= nums[mid]) {
					left = mid + 1;
				} else {
					if (target == nums[right]) {
						return right;
					} else if (target < nums[right]) {
						left = mid +1;
					} else {
						right = mid - 1;
					}
				}
			} else {
				if (nums[left] <= nums[mid]) {
					if (target == nums[left]) {
						return left;
					} else if (nums[left] < target) {
						right = mid - 1;
					} else {
						left = mid + 1;
					}
				} else {
					right = mid - 1;
				}
			}
		}
		return -1;
	}
};