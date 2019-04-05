class Solution {
public:
	bool isValid(string s) {
	stack<char> temp;
		
		for (int i = 0; i < s.size(); ++ i) {
			if (s[i] == ')') {
				if (temp.size() && temp.top() == '(') {
					temp.pop();
				} else {
					return false;
				}
			} else if (s[i] == ']') {
				if (temp.size() && temp.top() == '[') {
					temp.pop();
				} else {
					return false;
				}
			} else if (s[i] == '}') {
				
				if (temp.size() && temp.top() == '{') {
					temp.pop();
				} else {
					return false;
				}
			} else {
				temp.push(s[i]);
			}
		}
		return !temp.size();
	}
};