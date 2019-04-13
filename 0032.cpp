class Solution {
public:
	int longestValidParentheses(string s) {
		int index = 0, left = 0, result = 0;
		stack<int> start;//起点栈
		while (index < s.size()) {
			if (s[index] == '(') {//左括号直接入栈
				start.push(index);
			} else {//若为右括号
				if (start.empty()) {//若起点栈为空
					left = index + 1; //说明不匹配，重置当前工作区域的起点
				} else {//若起点栈不为空
					start.pop();//则抛弃配对的括号，且将上次设置的左括号的起点抛弃
					if (start.empty()) {//若起点栈为空，尝试用当前工作区域的匹配个数去更新目标值
						result = max(result, index - left + 1);
					} else {//若起点栈非空，则尝试使用使用最近一次的起点去更新目标值
						result = max(result, index - start.top());
					}
				}
			}
			++ index;
		}
		return result;
	}
};