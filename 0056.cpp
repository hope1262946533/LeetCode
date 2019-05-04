class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		if (intervals.size() < 2) {
			return intervals;
		}
		
		sort(intervals.begin(), intervals.end(), cmp);
		
		vector<vector<int>> result;
		result.push_back(intervals[0]);
		
		for (int i = 1; i < intervals.size(); ++ i) {
			int last_index = result.size() - 1;
			if (result[last_index][1] >= intervals[i][0]) {
				result[last_index][1] = max(result[last_index][1], intervals[i][1]);
			} else {
				result.push_back(intervals[i]);
			}
		}
		return result;
	}
	static bool cmp(const vector<int> &a, const vector<int> &b) {
		return a[0] < b[0];
	}
};