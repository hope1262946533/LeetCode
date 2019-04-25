class Solution {
public:
	bool isMatch(string s, string p) {
		int i = 0, j = 0, star = -1, current = 0;
		while (i < s.size()) {
			if (s[i] == p[j] || p[j] == '?') {
				++ i;
				++ j;
			} else if (p[j] == '*') {
				star = j;
				current = i;
				++ j;
			} else if (star != -1) {//匹配失败但星号存在
				i = current + 1;
				j = star + 1;
				++ current;
			} else {
				break;
			}
		}
		return i == s.size() && allStar(p, j);
	}
	
	bool allStar(const string &p, int index) {
		for (int i = index; i < p.size(); ++ i) {
			if (p[i] != '*') {
				return false;
			}
		}
		return true;
	}
};