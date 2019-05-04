class Solution {
public:
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int index = findInsertIndex(intervals, newInterval);
		intervals.insert(intervals.begin() + index, newInterval);
		return merge(intervals);
	}
	
	int findInsertIndex(const vector<vector<int>>& intervals, const vector<int>& newInterval) {
		int len = intervals.size();
		for (int i = 0; i < len; ++ i) {
			if (intervals[i][0] >= newInterval[0]) {
				return i;
			}
		}
		return len;
	}

	vector<vector<int>> merge(const vector<vector<int>>& intervals) {
		if (intervals.size() < 2) {
			return intervals;
		}
		
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
};