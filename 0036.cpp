class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		bool flag = false;
		judge(board, 0, flag);
		return flag;
	}

	void judge(vector<vector<char>>& board, int site, bool& flag) {
		int row = board.size(), column = board[0].size();
		int cur_x = site / column, cur_y = site % column;

		if (site == 81) {
			flag = true;
			return;
		}
		if (isValid(board, site)) {
			judge(board, site + 1, flag);
			if (flag) {
				return;
			}
		}
		return;
	}
	bool isValid(vector<vector<char>>& board, int site) {
		int row = board.size(), column = board[0].size();
		int cur_x = site / column, cur_y = site % column;

		//判断行
		bool visit_row[10] = { 0 };
		for (int i = 0; i < row; ++i) {
			if (board[cur_x][i] != '.') {
				int num = board[cur_x][i] - '0';
				if (visit_row[num]) {
					return false;
				}
				visit_row[num] = 1;
			}
		}

		//判断列
		bool visit_column[10] = { 0 };
		for (int i = 0; i < row; ++i) {
			if (board[i][cur_y] != '.') {
				int num = board[i][cur_y] - '0';
				if (visit_column[num]) {
					return false;
				}
				visit_column[num] = 1;
			}
		}

		//判断相邻的九块
		bool visit_bulk[10] = { 0 };
		int start_x = cur_x / 3 * 3, start_y = cur_y / 3 * 3;
		for (int j = 0; j < 3; ++j) {
			for (int k = 0; k < 3; ++k) {
				int temp_x = start_x + j, temp_y = start_y + k;
				if (board[temp_x][temp_y] != '.') {
					int num = board[temp_x][temp_y] - '0';
					if (visit_bulk[num]) {
						return false;
					}
					visit_bulk[num] = 1;
				}
			}
		}
		return true;
	}
};