class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		for (int i = nums1.size() - 1; i >= m; -- i) {
			nums1.pop_back();
		}
		
		for (int i = 0; i < n; ++ i) {
			nums1.push_back(nums2[i]);
		}
		sort(nums.begin(), nums.begin() + m + n);
	}
};