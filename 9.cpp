
class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0) {
        	return false;
		}
		long long reverse = 0, target = x;
        while (target) {
        	reverse *= 10;
        	reverse += target % 10;
        	target /= 10;
		}
		return reverse == x;
    }
};

