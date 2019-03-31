class Solution {
public:
	int sign[128];
	void init() {
		sign['I'] = 1;
		sign['V'] = 5;
		sign['X'] = 10;
		sign['L'] = 50;
		sign['C'] = 100;
		sign['D'] = 500;
		sign['M'] = 1000;
	}
	
    int romanToInt(string s)  {
    	init();
        int result = 0;
        for (int i = 0; i < s.size(); ++ i) {
        	int value = sign[s.at(i)];
        	if (i + 1 < s.size() && sign[s.at(i)] < sign[s.at(i + 1)]) {
        		value =  sign[s.at(i + 1)] - sign[s.at(i)];
        		++ i;
			}
			result += value;
		} 
		return result;
    }
};
