class Solution {
public:
    string simplifyPath(string path) {
		int current = 0;
		for (int i = 1; i < path.size(); ++ i) {
			if (path[i] == '/') {
				if (path[current] != '/') {
					path[++ current] = '/';
				}
			} else if (onePoint(path, i)) {//只有一个点
				++ i;
			} else if (twoPoint(path, i)) {//有连续两个点
				if (current) {//若非根目录
					-- current;
					while (path[current] != '/') {
						-- current;
					}
				} else {
					++ i;//跳过这两个点
				}
			} else {//对于其他情况，认为是路径名
				while (i < path.size() && path[i] != '/') {
					path[++ current] = path[i];
					++ i;
				}
				-- i;
			}
		}
		if (!current || path[current] != '/') {
			++ current;
		}
		return path.substr(0, current);
	}
	bool onePoint(const string &s, int index) {
		if (s[index] != '.') {//当前位置不为点
			return false;
		}
		if (index + 1 >= s.size()) {//已到顶部
			return true;
		}
		return s[index + 1] == '/';
	}
	
	bool twoPoint(const string &s, int index) {
		if (s[index] != '.' || index + 1 >= s.size() || s[index + 1] != '.') {//当前位置不为点
			return false;
		}
		++ index;
		
		if (index + 1 >= s.size()) {//已到顶部
			return true;
		}
		return s[index + 1] == '/';
	}
};