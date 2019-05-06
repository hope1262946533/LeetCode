class Solution {
public:
	int uniquePaths(int m, int n) {
		if (!m || !n) {
			return 0;
		}
		return combination(m + n - 2, m - 1);
	}
	int combination(int n, int x) {
		if (x > n - x) {
			x = n - x;
		}
		long long result = 1, factor = 1, temp = x;
		while(factor <= x || temp) {
			if (temp) {
				result *= (n - temp + 1);
				-- temp;
			}
			while (factor <= x && result % factor == 0) {
				result /= factor;
				++ factor;
			}
		}
		return (int)result;
	}
};