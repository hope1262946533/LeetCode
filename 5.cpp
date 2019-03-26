class Solution {
public:
    string longestPalindrome(string s) {
		string temp, result;
		
    	for (int i = 0; i < s.size(); ++i) {
    		temp = maxPalindrome(s, i, i);
    		if (temp.size > result.size()){
    			result = temp;
			}
			
			temp = maxPalindrome(s, i, i+1);
			if (temp.size > result.size()){
    			result = temp;
			}
		}
		return result;
    }
    
    string maxPalindrome(const string& s, int left, int right) {
		while (left > 0 && right < s.size()) {
    		if (s.at(left) != s.at(right)) {
    			break;
			}
			-- left;
			++ right;
		}
		return s.subString(left + 1, right - 1);
	}
};
