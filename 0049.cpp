class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> result;
		map<string, int> string_to_index;
		for (int i = 0; i < strs.size(); ++ i) {
			string temp = strs[i];
			sort(temp.begin(), temp.end());
			
			if (string_to_index.find(temp) == string_to_index.end()) {
				string_to_index[temp] = result.size();
				
				vector<string> item; 
				result.push_back(item);
			}
			result[string_to_index[temp]].push_back(strs[i]);
		}
		return result;
	}
};