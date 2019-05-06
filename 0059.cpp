class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<bool>> visit;
		vector<vector<int>> result;
		init(n, visit, result);
		
		int cnt = n * n, current = 1, i = 0, j = 0;
		
		while (cnt) {
			while (j < n && !visit[i][j]) {
				result[i][j] = current;
				visit[i][j] = true;
				++ j;
				-- cnt, ++ current;
			}
			++ i, -- j;
			
			while (i < n && !visit[i][j]) {
				result[i][j] = current;
				visit[i][j] = true;
				++ i;
				-- cnt, ++ current;
			}
			-- i, -- j;
			
			while (j >= 0 && !visit[i][j]) {
				result[i][j] = current;
				visit[i][j] = true;
				-- j;
				-- cnt, ++ current;
			}
			-- i, ++ j;
			
			while (i >= 0 && !visit[i][j]) {
				result[i][j] = current;
				visit[i][j] = true;
				-- i;
				-- cnt, ++ current;
			}
			++ i, ++ j;
		}
		return result;
	}
	
	void init(int n, vector<vector<bool>> &visit, vector<vector<int>> &result) {
		for (int i = 0; i < n; ++ i) {
			vector<bool> temp;
			vector<int> num;
			for (int j = 0; j < n; ++ j) {
				temp.push_back(false);
				num.push_back(0);
			}
			visit.push_back(temp);
			result.push_back(num);
		}
	}
};