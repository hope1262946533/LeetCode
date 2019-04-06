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
	ListNode* swapPairs(ListNode* head) {
		ListNode* my_head = new ListNode(0);
		my_head->next = head;
		ListNode* current = my_head;
		while (current->next && current->next->next) {
			ListNode* first = current->next;
			ListNode* second = first->next;
			
			current->next = second;
			first->next = second->next;
			second->next = first;
			
			current = current->next;
			current = current->next;
		}
		return my_head->next;
	}
};