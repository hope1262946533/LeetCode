class Solution {
public:
	string minWindow(string s, string t) {
		int len = s.size(), begin = 0, end = -1;
		int cnt = t.size();

		int count[256] = { 0 };
		for (int i = 0; i < t.size(); ++i) {
			++ count[t[i]];
		}

		int start = 0;
		int visit[256] = { 0 };
		for (int i = 0; i < len; ++ i) {
			++ visit[s[i]];
			if (visit[s[i]] > count[s[i]]) {
				continue;
			}
			-- cnt;
			while (!cnt) {
				if (end == -1 || i - start < end - begin) {//找到更短的了
					begin = start;
					end = i;
				}
				-- visit[s[start]];
				if (visit[s[start]] < count[s[start]]) {
					++ cnt;
				}
				++start;
			}
		}
		return s.substr(begin, end - begin + 1);
	}
};