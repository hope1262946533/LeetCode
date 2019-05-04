class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> result;
		int n = matrix.size();
		if (!n) {
			return result;
		}
		vector<vector<bool>> visit;
		initVisit(matrix, visit);
		
		int m = matrix[0].size(), cnt = n * m, i = 0, j = 0;
		while (cnt) {
			while (j < m && !visit[i][j]) {
				result.push_back(matrix[i][j]);
				visit[i][j ++] = true;
				-- cnt;
			}
			-- j, ++ i;
			while (i < n && !visit[i][j]) {
				result.push_back(matrix[i][j]);
				visit[i ++][j] = true;
				-- cnt;
			}
			-- i, -- j;
			while (j >= 0 && !visit[i][j]) {
				result.push_back(matrix[i][j]);
				visit[i][j --] = true;
				-- cnt;
			}
			++ j, -- i;
			while (i >= 0 && !visit[i][j]) {
				result.push_back(matrix[i][j]);
				visit[i --][j] = true;
				-- cnt;
			}
			++ i, ++ j;
		}
		return result;
	}
	void initVisit(vector<vector<int>>& matrix, vector<vector<bool>>& visit) {
		int row = matrix.size(), column = matrix[0].size();
		for (int i = 0; i < row; ++ i) {
			vector<bool> temp;
			for (int j = 0; j < column; ++ j) {
				temp.push_back(false);
			}
			visit.push_back(temp);
		}
	}
};