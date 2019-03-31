class Solution {
public:
	char sign[4][10][5] = {
		{"I", "II", "III", "IV", "V", "VI", "VII", "VIII" ,"IX"},
		{"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX" ,"XC"},
		{"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC" ,"CM"},
		{"M", "MM", "MMM"}
	}; 
	
    string intToRoman(int num) {
        int number[4] = {0}, index = 0;
		for (int i = 0; num > 0; ++ i) {
			number[i] = num % 10;
			num /= 10;
			++ index;
		}
		string result;
		
		while (index) {
			if (number[index - 1]) {
				result = result + sign[index - 1][number[index - 1] - 1];
			}
			-- index;
		}
		return result;
    }
};

