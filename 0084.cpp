/*
//1600+MS卡过的解法
class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		if (!heights.size()) {
			return 0;
		}
		
		vector<int> start;
		start.push_back(0);
		for (int i = 1; i < heights.size(); ++ i) {
			if (heights[i - 1] < heights[i]) {
				start.push_back(i);
			}
		}
		
		int result = 0;
		for (int i = 0; i < start.size(); ++ i) {
			int min_index = start[i];
			for (int j = start[i]; j < heights.size(); ++ j) {
				if (heights[j] < heights[min_index]) {
					min_index = j;
				}
				int sum = heights[min_index] * (j - start[i] + 1);
				result = max(result, sum);
			}
		}
		return result;
	}
};
*/

//最优解法，12MS
class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		heights.push_back(0);
		int result = 0;
		stack<int> start;
		for (int i = 0; i < heights.size(); ++ i) {
			while (!start.empty() && heights[i] <= heights[start.top()]) {
                int index = start.top();
                start.pop();
				result = max(result, heights[index] * (start.empty() ? i : i - start.top() - 1) );
			}
			start.push(i);
		}
		return result;
	}
};