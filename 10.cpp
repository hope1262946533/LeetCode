class Solution {
public:
    bool isMatch(string s, string p) {
    	if (p.empty()) {//若模式串为空 
    		return s.empty(); //是否匹配成功取决于匹配串是否为空 
		}
		
		if (p.size() == 1) {//若模式串长度为1 
			//在匹配串长度为1时，对应位置相同或模式串为.时才为真 
			return (s.size() == 1 && (s.at(0) == p.at(0) || p.at(0) == '.'));
		}
		if (p.at(1) != '*') {//第二个不是*结构 
			if (s.empty()) {//模式串为空则失败 
				return false;
			}
			//在首字符能匹配后尝试匹配后续字符 
			return (s.at(0) == p.at(0) || p.at(0) == '.') && isMatch(s.substr(1), p.substr(1));
		}
		
		//匹配串不为空，首字符相同或为模式串的首字符.时 
		while (!s.empty() && (s.at(0) == p.at(0) || p.at(0) == '.')) {
			if (isMatch(s, p.substr(2))) {//使用模式串的后续部分和匹配串尝试进行匹配 
				return true;
			}
			s = s.substr(1);//到达这一步说明中间出现了*，s的当前第一个字符可以被匹配 
		}
		
		//首字符不同且模式串的首字符不为.时，比较匹配串和模式串的后面部分 
		return isMatch(s, p.substr(2)); 
    }
};


