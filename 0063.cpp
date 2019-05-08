class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int n = obstacleGrid.size();
		if (!n) {
			return 0;
		}
		int m = obstacleGrid[0].size();
		
		vector<vector<long>> cnt;
		
		for (int i = 0; i < n; ++ i) {
			vector<long> row;
			int top = 0;
			if (i == 0) {
				if (!obstacleGrid[i][0]) {
					top = 1;
				}
			} else {
				if (!obstacleGrid[i][0]) {
					top = cnt[i - 1][0];
				}
			}
			row.push_back(top);//每行第一个数
			
			for (int j = 1; j < m; ++ j) {
				int temp = 0;
				if (i) {
					temp += cnt[i - 1][j];
				}
				temp += row[j - 1];
				
				if (obstacleGrid[i][j]) {
					temp = 0;
				}
				row.push_back(temp);
			}
			cnt.push_back(row);
		}
		return cnt[n - 1][m - 1];
	}
	
};