class Solution {
public:
	string addBinary(string a, string b) {
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		
		string result;
		int carry = 0, i = 0, j = 0;
		while (carry || i < a.size() || j < b.size()) {
			int temp = carry;
			if (i < a.size()) {
				temp += a[i] - '0';
			}
			if (j < b.size()) {
				temp += b[j] - '0';
			}
			carry = temp / 2;
			temp %= 2;
			result.push_back(temp + '0');
			
			++i, ++j;
		}
		
		return reverse(result.begin(), result.end());
	}
};