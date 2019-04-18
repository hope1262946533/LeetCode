class Solution {
public:
	string countAndSay(int n) {
		string result = "1";
		if (n == 1) {
			return result;
		}
		
		for (int i = 1; i < n; ++ i) {
			result = sayString(result);
		}
		
		return result;
	}
	string sayString(const string &target) {
		int index = 0, len = target.size();
		string result;
		while (index < len) {
			int temp = countItem(target, index);
			result += to_string(temp) + target[index];
			index += temp;
		}
		return result;
	}
	
	int countItem(const string &target, int index) {
		char temp = target[index];
		int result = 1;
		for (int i = index + 1; target[i] == temp; ++ i) {
			++ result;
		}
		return result;
	}
};