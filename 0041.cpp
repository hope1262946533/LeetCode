class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		int len = nums.size();
		vector<bool> visit;
		for (int i = 0; i < len + 2; ++ i) {
			visit.push_back(false);//先初始化为全false
		}
		
		for (int i = 0; i < len; ++ i) {
			if (nums[i] > 0 && nums[i] <= len) {
				visit[nums[i]] = true;
			}
		}
		for (int i = 1; i < len + 2; ++ i) {
			if (!visit[i]) {
				return i;
			}
		}
		return len + 1;
	}
};