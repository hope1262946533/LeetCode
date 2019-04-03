class Solution {
public:
	char number[10][6] ={
	"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
	};
	
    vector<string> letterCombinations(string digits) {
    	vector<string> temp;
        for (int i = 0; i < digits.size(); ++ i) {
        	int value =  digits[i] - '0';
        	temp.push_back(number[value]);
		}
		
		vector<string> result;
		getString(temp, 0, "", result);
		
		return result;
    }
    
    void getString(const vector<string>& digit_vector, int index, string current_string, vector<string>& result) {
		if (index >= digit_vector.size()) {
			if (current_string.size()) {
				result.push_back(current_string);
			}
    		return;
		}
    	for(int i = 0; i < digit_vector[index].size(); ++ i) {
			string temp = current_string + digit_vector[index][i];
			getString(digit_vector, index + 1, temp, result);
		}
	}
};
