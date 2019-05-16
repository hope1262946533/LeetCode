class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		int n = matrix.size();
		if (!n) {
			return ;
		}
		int m = matrix[0].size();
		if (!m) {
			return ;
		}
		vector<bool> row(n, false);
		vector<bool> column(m, false);
		for (int i = 0; i < n; ++ i) {
			for (int j = 0; j < m; ++ j) {
				if (!matrix[i][j]) {
					row[i] = true;
					column[j] = true;
				}
			}
		}
		for (int i = 0; i < n; ++ i) {
			for (int j = 0; j < m; ++ j) {
				if (row[i] || column[j]) {
					matrix[i][j] = 0;
				}
			}
		}
        
	}
};