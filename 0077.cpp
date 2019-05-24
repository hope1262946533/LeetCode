class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		vector<bool> visit(n, 0);
		vector<vector<int>> result;
		vector<int> current;
		dfs(k, current, visit, result);
		return result;
	}
	
	void dfs(int k, vector<int> &current, vector<bool> &visit, vector<vector<int>> &result) {
		
		if (!k) {
			result.push_back(current);
			return ;
		}
		for (int i = current.size(); i < visit.size(); ++ i) {
			if (!visit[i]) {
				visit[i] = 1;
				if (!current.size() || i >=  current[current.size() - 1]) {
					current.push_back(i + 1);
					dfs(k - 1, current, visit, result);
					current.pop_back();
				}
				visit[i] = 0;
			}
		}
	}
};