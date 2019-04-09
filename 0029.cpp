class Solution {
public:
	int divide(int dividend, int divisor) {
		int sign = (dividend > 0) == (divisor > 0) ? 1 : -1;
		long long result = 0, a = abs(dividend), b = abs(divisor);
		while (a >= b) {
			unsigned long long temp = b, base = 1;
			while (temp << 1 < a) {
				temp <<= 1;
				base <<= 1;
			}
			a -= temp;
			result += base;
		}

		result = sign * result;
		if (result > INT_MAX || result < INT_MIN) {
			result = INT_MAX;
		}
		return (int)result; 
	}
	long long abs(long long x) {
		return x > 0 ? x : - x;
	}
};
