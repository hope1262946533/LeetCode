class Solution {
public:
	int minDistance(string word1, string word2) {
		int lena = word1.size(), lenb = word2.size();
		if (lena == 0 || lenb == 0) {
			return max(lena, lenb);
		}
		
		vector<int> previous;
		vector<int> current;
		current.push_back(word1[0] != word2[0]);
		for (int i = 1; i < lenb; ++ i) {
			int temp = current.back() + (word1[0] != word2[i]);
			temp = max(temp, abs(i));
			current.push_back(temp);
		}
		previous = current;
		
		for (int i = 1; i < lena; ++ i) {
			current.clear();
			
			int temp = previous[0] + (word1[i] != word2[0]);
			temp = max(temp, abs(i));
			current.push_back(temp);
			
			for (int j = 1; j < lenb; ++ j) {
				int temp = 1 + min(previous[j], current[j - 1]);
				if (word1[i] == word2[j]) {//相同
					temp = min(temp, previous[j - 1]);
				} else {
					temp = min(temp, 1 + previous[j - 1]);
				}
				
				current.push_back(temp);
			}
			previous = current;
		}
		return previous[lenb - 1];
	}
};