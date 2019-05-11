class Solution {
public:
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		int len = words.size(), index = 0;
		vector<string> result;
		while (index < len) {
			int num = maxNumber(words, maxWidth, index);
			string row = justified(words, maxWidth, index, num);
			result.push_back(row);
			index += num;
		}
		return result;
	}
	int maxNumber(vector<string>& words, int maxWidth, int index) {
		int result = 1, current = words[index].size();
		for (int i = index + 1; i < words.size(); ++ i) {
			int len = words[i].size();
			if (current + len + 1 > maxWidth) {
				break;
			}
			current += len + 1;
			++ result;
		}
		return result;
	}
	string justified(vector<string>& words, int maxWidth, int index, int num) {
		string result;
		int wordLen = 0;
		for (int i = 0; i < num; ++ i) {//统计有效单词的数量
			wordLen += words[i + index].size();
		}
		
		int spaceNum = maxWidth - wordLen;
		for (int i = 0; i < num; ++ i) {
			result += words[i + index];
			
			if (result.size() < maxWidth) {
				int evenSpaceNum = num == 1 ? spaceNum : spaceNum / (num - 1);
				if (index + num == words.size()) {//最后一行要特殊处理
					evenSpaceNum = 1;
				} else if (num > 1 && i < spaceNum % (num - 1 ) ) {
					++ evenSpaceNum;
				}
				for (int j = 0; j < evenSpaceNum; ++ j) {
					result.push_back(' ');
				}
			}
		}
		while (result.size() < maxWidth) {
			result.push_back(' ');
		}
		return result;
	}
};