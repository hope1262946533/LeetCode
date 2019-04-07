/*
//solution 1
class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle.size() == 0) {
			return 0;
		}
		
		for (int i = 0; i < haystack.size(); ++ i) {
			if (isSucceed(haystack, i, needle)) {
				return i;
			}
		}
		return -1;
	}
    
	bool isSucceed(const string &haystack, int start, const string &needle) {
		int index = start, i = 0;
		while (index < haystack.size() && i < needle.size()) {
			if (haystack[index] != needle[i]) {
				return false;
			}
			++ index;
			++ i;
		}
		return i == needle.size();//返回是否匹配成功
	}
};
*/

//solution 2, kmp 
class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle.size() == 0) {
			return 0;
		}
		vector<int> next;
		get_next(needle, next);
		int result = kmp(haystack, needle, next);
		return result;
	}
	void get_next(string needle, vector<int> &next) {
		int i = 0, j = -1;
		next.push_back(-1);
		while (i < needle.size()) {
			if (j == -1 || needle[i] == needle[j]) {
				++ i;
				++ j;
				next.push_back(j);
			} else {
				j = next[j];
			}
		}
	}
	int kmp(const string &haystack, const string &needle, const vector<int> &next) {
		int i = 0, j = 0;
		while (i < haystack.size()) {
			if (j == -1 || haystack[i] == needle[j]) {
				++ i; 
				++ j;
				if (j == needle.size()) {
					return i - needle.size();
				}
			} else {
				j = next[j];
			}
		}
		return -1;
	}
};