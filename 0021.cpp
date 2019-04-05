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
	ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
		ListNode *my_head = new ListNode(0);
		ListNode *tail = my_head;
		
		while (a && b) {
			if (a->val < b->val) {
				tail->next = a;
				a = a->next;
			} else {
				tail->next = b;
				b = b->next;
			}
			tail = tail->next;
		}
		while (a) {
			tail->next = a;
			a = a->next;
			tail = tail->next;
		}
		while (b) {
			tail->next = b;
			b = b->next;
			tail = tail->next;			
		}
		return my_head->next;
	}
};