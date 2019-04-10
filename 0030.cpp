class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (s.empty() || words.empty()) {
			return res;
		}
		
        int count = words.size(), len = words[0].size();
        map<string, int> string_map;
        for (int i = 0; i < words.size(); ++ i) {
			++ string_map[words[i]];
		}
        for (int i = 0; i <= (int)s.size() - count * len; ++ i) {
            map<string, int> substr_map;
            int index = 0; 
            while (index < count) {
                string temp = s.substr(i + index * len, len);
                if (string_map.find(temp) == string_map.end()) {
					break;
				}
				
                ++ substr_map[temp];
				
                if (substr_map[temp] > string_map[temp]) {
					break;
				}
				++ index;
            }
            if (index == count) {
				res.push_back(i);
			}
        }
        return res;
    }
};