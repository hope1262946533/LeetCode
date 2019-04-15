/*
//solution 1
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		
		int left = lower_bound(nums.begin(), nums.end(), target) - nums.begin(), right = -1;
		
		if (nums.size() && left < nums.size() && nums[left] == target) {
			right = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
		} else {
			left = - 1;
		}
		
		vector<int> result;
		result.push_back(left);
		result.push_back(right);
		return result;
	}
};
*/

//solution 2
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int left = find_left(nums, target), right = find_right(nums, target);
		vector<int> result;
		result.push_back(left);
		result.push_back(right);
		return result;
	}
	int find_left(const vector<int>& nums, int target) {
		int left = 0, right = nums.size() - 1, mid;
		while (left <= right) {
			mid = (left + right) >> 1;
			if (nums[mid] >= target) {
				right = mid - 1;
			} else {
				left = mid + 1;
			}
		}
		return left >= 0 && left < nums.size() && nums[left] == target ? left : -1;
	}
	int find_right(const vector<int>& nums, int target) {
		int left = 0, right = nums.size() - 1, mid;
		while (left <= right) {
			mid = (left + right) >> 1;
			if (nums[mid] <= target) {
				left = mid + 1;
			} else {
				right = mid - 1;
			}
		}
		return right >= 0 && right < nums.size() && nums[right] == target ? right : -1;
	}
};