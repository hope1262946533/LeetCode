class Solution {
public:
	vector<int> grayCode(int n) {         
		vector<int> result;
		result.push_back(0);
		for (int i = 0; i < n; ++i) {
			int size = result.size();
			while (size--) {
				int curNum = result[size];
				curNum += (1 << i);
				result.push_back(curNum);
			}
		}
		return result;
	}
};