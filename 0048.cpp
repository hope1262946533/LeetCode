class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
        Transposition(matrix);
		LeftRightSwap(matrix);
	}
	void Transposition(vector<vector<int>>& matrix) {
	 	for (int i = 0; i < matrix.size(); ++ i) {
			for (int j = 0; j < i; ++ j) {
				swap(matrix[i][j], matrix[j][i]);
			}
		}
	}
	void LeftRightSwap(vector<vector<int>>& matrix) {
		
		for (int i = 0; i < matrix.size(); ++ i) {
			int len = matrix[i].size();
			for (int j = 0; j <  len / 2; ++ j) {
				 swap(matrix[i][j], matrix[i][len - j - 1]);
			}
		}
	}
};