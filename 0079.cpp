class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		
		for (int i = 0; i < board.size(); ++ i) {
			for (int j = 0; j < board[0].size(); ++ j) {
				if (board[i][j] != word[0]) {
					continue;
				}
				if (match(board, word, 0, i, j)) {
					return true;
				}
			}
		}
		return false;
	}
	bool match(vector<vector<char>>& board, const string &word, int index, int row, int column) {
		
		int n = board.size(), m = board[0].size();
		if (index == word.size()) {
			return true;
		}
		if (row < 0 || row >= n || column < 0 || column >= m || board[row][column] != word[index]) {
			return false;
		}
		int temp = board[row][column];
		board[row][column] = 0;
		
		for (int i = -1; i <= 1; ++ i) {
			for (int j = -1; j <= 1; ++ j) {
				if (abs(i) == abs(j)) {
					continue;
				}
				if (match(board, word, index + 1, row + i, column + j)) {
					return true;
				}
			}
		}
		if (!board[row][column]) {
			board[row][column] = temp;
		}
		return false;
	}
};