class Solution {
public:
    bool isMatch(string s, string p) {
    	if (p.empty()) {//��ģʽ��Ϊ�� 
    		return s.empty(); //�Ƿ�ƥ��ɹ�ȡ����ƥ�䴮�Ƿ�Ϊ�� 
		}
		
		if (p.size() == 1) {//��ģʽ������Ϊ1 
			//��ƥ�䴮����Ϊ1ʱ����Ӧλ����ͬ��ģʽ��Ϊ.ʱ��Ϊ�� 
			return (s.size() == 1 && (s.at(0) == p.at(0) || p.at(0) == '.'));
		}
		if (p.at(1) != '*') {//�ڶ�������*�ṹ 
			if (s.empty()) {//ģʽ��Ϊ����ʧ�� 
				return false;
			}
			//�����ַ���ƥ�����ƥ������ַ� 
			return (s.at(0) == p.at(0) || p.at(0) == '.') && isMatch(s.substr(1), p.substr(1));
		}
		
		//ƥ�䴮��Ϊ�գ����ַ���ͬ��Ϊģʽ�������ַ�.ʱ 
		while (!s.empty() && (s.at(0) == p.at(0) || p.at(0) == '.')) {
			if (isMatch(s, p.substr(2))) {//ʹ��ģʽ���ĺ������ֺ�ƥ�䴮���Խ���ƥ�� 
				return true;
			}
			s = s.substr(1);//������һ��˵���м������*��s�ĵ�ǰ��һ���ַ����Ա�ƥ�� 
		}
		
		//���ַ���ͬ��ģʽ�������ַ���Ϊ.ʱ���Ƚ�ƥ�䴮��ģʽ���ĺ��沿�� 
		return isMatch(s, p.substr(2)); 
    }
};


