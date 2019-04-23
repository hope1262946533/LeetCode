class Solution {
public:
	int trap(vector<int>& height) {
		int len = height.size();
		if (len < 3) {
			return 0;
		}
		vector<int> num;
		for (int i = 1; i < len; ++ i) {
			if (height[i - 1] > height[i]) {
				int count = num.size();
				if (!count || num[count - 1] != i - 1) {
					num.push_back(i - 1);
				}
			} else {
				int count = num.size();
				while (count > 1 && height[num[count - 1]] < height[i] 
				&& height[num[count - 2]] >= height[num[count - 1]]) {
					num.pop_back();
					count = num.size();
				}
				num.push_back(i);
			}
		}
		
		int result = 0;
		for(int i = 1; i < num.size(); ++ i) {
			result += caculate(height, num[i - 1], num[i]);
		}		
		return result;
	}
	int caculate(const vector<int> &height, int left, int right) {
		int result = 0, border = height[left] < height[right] ? height[left] : height[right];
		for (int i = left + 1; i < right; ++ i) {
			result += (border - height[i]);
		}
		return result;
	}
};