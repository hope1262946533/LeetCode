class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode(0);
        ListNode* tail = result;
        ListNode* current;
        int temp = 0, carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry == 1) {
            temp = carry;
            carry = 0;
            if (l1) {
                temp += l1->val;
            }
            if (l2) {
                temp += l2->val;
            }
            
            //判断进位
            if (temp > 9) {
                carry = 1;
                temp %= 10;
            }
            
            //生成新结点
            current = new ListNode(temp);
            tail->next = current;
            tail = current;
            
            if (l1) {
                l1 = l1->next;
            }
            
            if (l2) {
                l2 = l2->next;
            }
        }
        
        return result->next;
    }
};
