class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    	if (strs.size()) {
    		return "";
		}
    	int min_length = strs.at(0).length();
    	for (int i = 0; i < strs.size(); ++ i) {
    		if (strs[i].length() < min_length) {
    			min_length = strs[i].length();
			}
		}
    	
        string result;
        for (int i = 0; i < min_length; ++ i) {
        	char current = strs[0].at(i);
        	bool flag = false;
        	for (int j = 0; j < strs.size(); ++ j) {
        		if (current != strs[j].at(i)) {
        			flag = true;
        			break;
				}
			}
			if (flag == true) {
				break;
			}
			result.push_back(current);
			
		}
		return result;
    }
};
