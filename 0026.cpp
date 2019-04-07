
//solution 1
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		return unique(nums.begin(), nums.end()) - nums.begin();
	}
};


//solution 2
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() < 2) {
			return nums.size();
		}
		
        int new_index = 0;
		for (int i = 1; i < nums.size(); ++ i) {
			if (nums[i] != nums[new_index]) {
				++ new_index;
				nums[new_index] = nums[i];
			}
		}
		return new_index + 1;
	}
};