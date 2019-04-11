//solution 1
// class Solution {
// public:
// void nextPermutation(vector<int>& nums) {
// next_permutation(nums.begin(), nums.end());
// }
// };

//solution 2
class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int len = nums.size();
		if (len < 2) {
			return;
		}
		int index = len - 2;
		bool flag = false;

		while (index >= 0) {
			if (nums[index] < nums[index + 1]) {
				flag = true;//标记是否遇到了正序数对
				break;
			}
			--index;
		}

		if (flag) {//若有正序数对
			int next = findFirstBigger(nums, index);
			swap(nums[index], nums[next]);
			reverse(nums, index + 1, len - 1);
		}
		else {
			reverse(nums, 0, len - 1);
		}
	}
	//寻找从index开始第一个比 index - 1位置处元素大的数的坐标
	int findFirstBigger(const vector<int>& nums, int index) {
		int result = nums.size() - 1;
		for (int i = result; i > index; -- i) {
			if (nums[i] > nums[index]) {
				result = i;
				break;
			}
		}
		return result;
	}
	void reverse(vector<int>& nums, int left, int right) {
		int len = right - left + 1;
		for (int i = 0; i < len / 2; ++i) {
			swap(nums[left + i], nums[right - i]);
		}
	}
};