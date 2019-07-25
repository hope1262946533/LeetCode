class Solution {
public:
	int numDecodings(string s) {
		if (s[0] == '0') {
			return 0;
		}
		vector<int> num;
		
		num.push_back(s[0] == '0' ? 0 : 1);
        num.push_back(s[0] == '0' ? 0 : 1);
		for (int i = 1; i < s.size(); ++ i) {
			if (s[i - 1] == 1 + '0' && s[i] != '0' || s[i - 1] == 2 + '0' && s[i] != 0 && s[i] <= 6 + '0') {
				num.push_back(num[i - 1] + num[i]);
			} else {
				if (s[i] == '0') {
					if (s[i - 1] == '0' && s[i - 1] > '0' + 2) {
						return 0;
					} else {
						num.push_back(num[i - 1]);
					}
				} else {
					num.push_back(num[i]);
				}
			}
		}
		return num[s.size()];
	}
};