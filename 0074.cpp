class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (!matrix.size() || !matrix[0].size()) {
			return false;
		}
		
		int left = 0, right = matrix.size() * matrix[0].size() - 1, mid;
		while(left <= right) {
			mid = (left + right) >> 1;
			int temp = getItem(matrix, mid);
			if (temp == target) {
				return true;
			} else if (temp < target) {
				left = mid + 1;
			} else {
				right = mid - 1;
			}
		}
		return false;
	}
	int getItem(const vector<vector<int>>& matrix, int index) {
		int column = matrix[0].size();
		return matrix[index / column][index % column];
	}
};