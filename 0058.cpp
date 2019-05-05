class Solution {
public:
	int lengthOfLastWord(string s) {
		int len = s.size(), result = 0, start = false;
		for (int i = len - 1; i >= 0 ; -- i) {
			if (s[i] != ' ') {
					start = true;
					++ result;
			} else {
				if (start) {
					break;
				}
			}
		}
		return result;
	}
};