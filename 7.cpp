class Solution {
public:
    int reverse(int x) {
		long long result = 0, target = x;
		
		target = x > 0 ? x : -(long long)x;
		while (target) {
			result *= 10;
			result += (target % 10);
			target /= 10;
		}
		result = x > 0 ? result : - result;
		if (result > ((long long)1 << 31) - 1 || result < (- ((long long)1 << 31))) {
			return 0;
		} else {
			return result;
		}
    }
};
