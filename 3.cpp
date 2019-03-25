class Solution {
public:
int lengthOfLongestSubstring(string s) {
        int length = 0, result = 0, left = 0;
		int temp[256] = {0};
        for (int i = 0; i < s.size(); ++ i) {
        	int right = s.at(i);
        	if (!temp[right]) {//如果某字符未出现过 
        		++ temp[right];
				length += 1;
				if (length > result) {
					result = length;
				}
			} else {//若某字符第二次出现
				++ length; 
				++ temp[right];//将第二次出现的位置累加 
				for (int j = i - length + 1; j < i; ++j) {//从左往右缩短，直到不出现重复的字母
					-- length;
					int left = s.at(j);
					-- temp[left];
					if (temp[left]) {//说明已经缩到无重复字母的最左侧
						break; 
					}
				}
			}
		}
		return result;
    }
};
