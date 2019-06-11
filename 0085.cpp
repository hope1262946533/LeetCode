class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		if (!matrix.size() || !matrix[0].size()) {
			return 0;
		}
		for (int i = 0; i < matrix.size(); ++ i) {
			matrix[i][0] -= '0';
			for(int j = 1; j < matrix[0].size(); ++ j) {
				matrix[i][j] = matrix[i][j] - '0' + matrix[i][j - 1];
			}
		}
		int result = 0;
		for (int i = 0; i < matrix[0].size(); ++ i) {
			for (int j = i; j < matrix[0].size(); ++ j) {
				caculate(matrix, i, j, result);
			}
		}
		return result;
	}
	void caculate(const vector<vector<char>>& matrix, int col_begin, int col_end, int &result) {
		int temp = 0, count = col_end - col_begin + 1;
		for (int i = 0; i < matrix.size(); ++ i) {
			int last_sum = 0;
			if (col_begin) {
				last_sum = matrix[i][col_begin - 1];
			}
			temp += count;
			int dis = matrix[i][col_end] - last_sum;
			if (dis != count) {
				temp = 0;
			}
			result = max(result, temp);
		}
	}
};