class Solution {
public:
    string convert(string s, int numRows) {
        string result;
		
		int dis =  (numRows - 1) * 2;
		int mid = dis;
		for (int i = 0; i < numRows; ++i) {
			int index = i;
			if (index >= s.size()) {
				break;
			}
			result.push_back(s.at(index));
			while (index < s.length()) {
				index += mid;
				
				if (mid != 0 && index < s.length()) {
					result.push_back(s.at(index));
				}
				
				if (mid == dis) {
					continue;
				} else {
					index += dis - mid;
				}
				if (index < s.length()) {
					result.push_back(s.at(index));
				}
			}
			mid -= 2;
		}
		return result;
    }
};

