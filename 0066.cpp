class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int len = digits.size(), index = len - 1;
		int carry = 1;
		while (carry && index >= 0) {
			digits[index] += carry;
			carry = digits[index] / 10;
			digits[index] %=10;
			-- index;
		}
		if (carry) {
			digits.insert(digits.begin(), 1);
		}
		return digits;
	}
};