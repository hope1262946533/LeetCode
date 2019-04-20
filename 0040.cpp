class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		set<vector<int>> result_set;

		vector<int> solution;
		findSolution(candidates, target, solution, 0, result_set);
		
		vector<vector<int>> result;
		result.assign(result_set.begin(), result_set.end());
		
		return result;
	}

	void findSolution(vector<int>& candidates, int target, vector<int>& solution, int index, set<vector<int>> &result_set) {

		if (target == 0) {
			result_set.insert(solution);
			return;
		}

		if (index == candidates.size()) {
			return;
		}

		findSolution(candidates, target, solution, index + 1, result_set);
		
		if (target >= candidates[index]) {
			solution.push_back(candidates[index]);
			target -= candidates[index];
			findSolution(candidates, target, solution, index + 1, result_set);
			solution.pop_back();
		}
	}

};
