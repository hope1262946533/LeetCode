class Solution {
public:
    vector< vector<int> > threeSum(vector<int>& nums) {
    	int len = nums.size(), i = 0;
    	//œ»≈≈–Ú 
    	sort(nums.begin(), nums.end());
    	
        vector< vector<int> > result;
        while (i < len) {
        	int target = - nums[i], j = i + 1, k = len - 1;
			while (j < k) {
				int current = nums[j] + nums[k];
				if (current < target) {
					++ j;
				} else if (current > target) {
					-- k;
				} else {
					vector<int> temp;
					temp.push_back(nums[i]);
					temp.push_back(nums[j]);
					temp.push_back(nums[k]);
					result.push_back(temp);
					
					int left = nums[j], right = nums[k];
					while(j < k && nums[j] == left) {
						++ j;
					}
					while(j < k && nums[k] == right) {
						-- k;
					}
				}
			}
			int count = upper_bound(nums.begin(), nums.end(), nums[i]) - 
			lower_bound(nums.begin(), nums.end(), nums[i]);
			i += count;
		}
        return result;
    }
};
