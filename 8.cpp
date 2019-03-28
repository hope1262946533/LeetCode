
class Solution {
public:
	int myAtoi(string str) {
	int sign = 0;
	string number;//存储截取下的数字串，不包含符号 
	for (int i = 0; i < str.size(); ++ i) {
		if ((str[i] == '-' || str[i] == '+' || str[i] == ' ') && !number.size()) {
			if (sign == 0) {
				if (str[i] == '-') {
					sign = -1;
				} else if (str[i] == '+') {
					sign = 1;
				} else {
					continue;
				}
			} else {
				break;
			}
		} else {
			if (str[i] >= '0' && str[i] <='9') {
				number.push_back(str[i]);
			} else {
				break;
			}
		}
	}
	if (!sign) {
		sign = 1;
	}
	long long result = 0;
	for (int i = 0; i < number.size(); ++ i) {
		result *= 10;
		result += sign * (number[i] - '0');
		if (result > INT_MAX || result < INT_MIN) {
			return result > 0 ? INT_MAX : INT_MIN;
		}
	}
	return (int)result;
	}
};
