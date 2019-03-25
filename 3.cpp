class Solution {
public:
int lengthOfLongestSubstring(string s) {
        int length = 0, result = 0, left = 0;
		int temp[256] = {0};
        for (int i = 0; i < s.size(); ++ i) {
        	int right = s.at(i);
        	if (!temp[right]) {//���ĳ�ַ�δ���ֹ� 
        		++ temp[right];
				length += 1;
				if (length > result) {
					result = length;
				}
			} else {//��ĳ�ַ��ڶ��γ���
				++ length; 
				++ temp[right];//���ڶ��γ��ֵ�λ���ۼ� 
				for (int j = i - length + 1; j < i; ++j) {//�����������̣�ֱ���������ظ�����ĸ
					-- length;
					int left = s.at(j);
					-- temp[left];
					if (temp[left]) {//˵���Ѿ��������ظ���ĸ�������
						break; 
					}
				}
			}
		}
		return result;
    }
};
