class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		vector<vector<int>> result;

		vector<int> solution;
		findSolution(candidates, target, solution, 0, 0, result);

		return result;
	}

	void findSolution(vector<int>& candidates, int target, vector<int>& solution, int sum, int index, vector<vector<int>> &result) {

		if (sum == target) {
			result.push_back(solution);
			return;
		}

		if (index == candidates.size()) {
			return;
		}

		findSolution(candidates, target, solution, sum, index + 1, result);
        
        // int max_count = target / candidates[index];//超时代码
		int max_count = (target - sum) / candidates[index];
        
		for (int i = 0; i < max_count; ++ i) {
			solution.push_back(candidates[index]);
			sum += candidates[index];
			findSolution(candidates, target, solution, sum, index + 1, result);
		}
		while (max_count--) {
			solution.pop_back();
		}
	}

};
