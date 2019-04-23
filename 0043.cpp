class Solution {
public:
	string multiply(string num1, string num2) {
		if (is_zero(num1) || is_zero(num2)) {
			return "0";
		}
		reverse(num1.begin(), num1.end());
		reverse(num2.begin(), num2.end());
				
		string result, base;
		int index = 0;
		while (index < num2.size()) {
			string temp = mul(num1, num2[index] - '0');
			result = add(result, base + temp);
			base.push_back('0');
			++ index;
		}
        reverse(result.begin(), result.end());
		return result;
	}
	
	bool is_zero(const string &a) {
		return a.size() == 1 && a[0] == '0';
	}
	
	string add(const string &a, const string &b) {
		string result;
		int index = 0, carry = 0;
		while (index < a.size() || index < b.size() || carry) {
			int temp = carry;
			if (index < a.size()) {
				temp += a[index] - '0';
			}
			if (index < b.size()) {
				temp += b[index] - '0';
			}
			carry = temp / 10;
			temp %= 10;
			result.push_back(temp + '0');
            ++ index;
		}
		return result;
	}
	
	string mul(string a, int digit) {
		string result;
		
		if (digit %10 == 10) {
			return result + '0';
		}
		
		int carry = 0, index = 0;
		while (index < a.size()) {
			int temp = (a[index] - '0') * digit + carry;
			carry = temp / 10;
			temp %= 10;
			result.push_back(temp + '0');
			++ index;
		}
		if (carry) {
			result.push_back(carry + '0');
		}
		return result;
	}
	
};