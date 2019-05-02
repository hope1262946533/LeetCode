class Solution {
public:
	int totalNQueens(int n) {
		vector<string> chess;
		initChess(n, chess);
		vector<bool> visit(n, false);
		int result = 0;
		findSolution(n, 0, chess, visit, result);
		return result;
	}
	void initChess(int n, vector<string> &chess) {
		for (int i = 0; i < n; ++ i) {
			string row;
			for (int i = 0; i < n; ++ i) {
				row.push_back('.');
			}
			chess.push_back(row);
		}
	}
	void findSolution(int n, int row, vector<string> &chess, vector<bool> &visit, int &result) {
		if (row == n) {
			++ result;
			return ;
		}
		
		for (int column = 0; column < n; ++ column) {
			if (!visit[column] && diagonalSafe(chess, row, column)) {
				chess[row][column] = 'Q';
				visit[column] = true;
				findSolution(n, row + 1, chess, visit, result);
				chess[row][column] = '.';
				visit[column] = false;
			}
		}
	} 
	bool diagonalSafe(vector<string> &chess, int row, int column) {
		int row_count = chess.size(), column_count = chess[0].size();
		//主对角线
		for (int i = row + 1, j = column + 1; i < row_count && j < column_count; ++ i, ++ j) {
			if (chess[i][j] == 'Q') {
				return false;
			}
		}
		for (int i = row - 1, j = column - 1; i >= 0 && j >= 0; -- i, -- j) {
			if (chess[i][j] == 'Q') {
				return false;
			}
		}
		
		//副对角线
		for (int i = row + 1, j = column - 1; i < row_count && j >= 0; ++ i, -- j) {
			if (chess[i][j] == 'Q') {
				return false;
			}
		}
		for (int i = row - 1, j = column + 1; i >= 0 && j < column_count; -- i, ++ j) {
			if (chess[i][j] == 'Q') {
				return false;
			}
		}
		return true;
	}
};
