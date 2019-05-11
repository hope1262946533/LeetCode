class Solution {
public:
	int climbStairs(int n) {
		int a = 0, b = 1, c = b;
		
		while (n --) {
			c = a + b;
			b = a;
			a = c;
		}
		return c;
	}
};