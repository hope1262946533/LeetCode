class Solution {
public:
	bool isNumber(string s) {
		bool is_start = false, num_start = false, has_sign = false, has_point = false;
		for (int i = 0; i < s.size(); ++ i) {
			if (!is_start && s[i] == ' ') { //没开始的时候，空格可以任意多个
				continue;
			}
			is_start = true;//遇到非空格，即认为数字已经开始了
			if (isNumber(s[i])) {
				num_start = true;
			} else if (s[i] == '+' || s[i] == '-') {
				if (has_sign || num_start || has_point) {//包含多个符号
					return false;
				}
				has_sign = true;
			} else if (s[i] == '.') {
				if (has_point) {
					return false;
				}
				has_point = true;
			} else if (s[i] == 'e') {//若有e，则前面必须有数字，后边必须为整数
				return num_start && isIntrger(s, i + 1);
			} else if (s[i] == ' '){//其他情况
				return num_start && isEmpty(s, i + 1);
			} else {
				return false;
			}
		}
		return num_start;//对于循环结束的
	}
	bool isIntrger(const string &s, int start) {
		bool has_sign = false, has_start = false;
		for (int i = start; i < s.size(); ++ i) {
			if (s[i] == '+' || s[i] == '-') {
				if (has_sign  || has_start) {
					return false;
				}
				has_sign = true;
			} else if (isNumber(s[i])) {
				has_start = true;
			} else {//不是数字或者正负号
				return has_start && isEmpty(s, i);
			}
		}
		return has_start;
	}
	bool isNumber(char ch) {
		return '0' <= ch && ch <= '9';
	}
	bool isEmpty(const string &s, int start) {
		for (int i = start; i < s.size(); ++ i) {
			if (s[i] != ' ') {
				return false;
			}
		}
		return true;
	}
};