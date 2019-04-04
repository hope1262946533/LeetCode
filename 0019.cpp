/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode *my_head = new ListNode(0);//临时的头结点
		my_head->next = head;
        ListNode *left = my_head, *right = my_head;
		while (n) {
			right = right->next;
			-- n;
		}
		while (right && right->next) {
			left = left->next;
			right = right->next;
		}
		ListNode *temp = left->next;
		left->next = temp->next;
		delete temp;
		return my_head->next;
    }
};