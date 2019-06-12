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
	ListNode* partition(ListNode* head, int x) {
		ListNode *my_head = new ListNode(0);
		ListNode *my_tail = my_head;
		ListNode *bigger_head = new ListNode(0);
		ListNode *bigger_tail = bigger_head;
		
		my_head->next = head;
		
		while (my_tail->next) {
			if (my_tail->next->val < x) {
				my_tail = my_tail->next;
			} else {
				bigger_tail->next = my_tail->next;
				bigger_tail = bigger_tail->next;
				my_tail->next = bigger_tail->next;
				bigger_tail->next = nullptr;
			}
		}
		my_tail->next = bigger_head->next;
		delete bigger_head;
		
		return my_head->next;
	}
};