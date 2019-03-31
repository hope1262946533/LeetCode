//solution 1
class Solution {
public:
	int min(int a, int b) {
		return a > b ? b: a;
	}
    int maxArea(vector<int>& height) {
        int result = 0, current = 0;
		
		for (int i = 0; i < height.size(); ++i) {
			for (int j = i + 1; j < height.size(); ++j) {
				current = min(height[i], height[j]) * (j - i);
				if (current > result) {
					result = current;
				}
			}
		}
        return result;
    }
};


//solution 2 
class Solution {
public:
	int min(int a, int b) {
		return a > b ? b: a;
	}
    int maxArea(vector<int>& height) {
    	int left = 0, right = height.size() - 1;
        int result = 0, current = 0;
		
		do {
			current = min(height[left], height[right]) * (right - left);
			if (current > result) {
				result = current;
			}
			if (height[left] < height[right]) {
				++ left;
			} else {
				-- right;
			}
		} while (left < right);
        return result;
    }
};
