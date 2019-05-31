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
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode *my_head = new ListNode(0);
		ListNode *current = my_head;
		my_head->next = head;
		bool flag = false;
		while (current->next && current->next->next) {
			ListNode *temp = current->next->next;
			if (current->next->val == temp->val) {
				current->next->next = temp->next;
				delete temp;
				flag = true;
			} else {
				
				if (flag) {
					delete current->next;
					current->next = temp;
					flag = false;
				} else {
					current = current->next;
				}
			}
		}
		if (flag) {
			ListNode *temp = current->next->next;
			delete current->next;
			current->next = temp;
		}
		return my_head->next;
	}
};