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
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		ListNode* my_head = new ListNode(0);
		my_head->next = head;
		ListNode* first_node = my_head;
		int count = n - m + 1;
		while (-- m) {
			first_node = first_node->next;
		}
		
		ListNode* new_head = new ListNode(0);
		ListNode* new_tail = first_node->next;
		while(count --) {
			ListNode* temp = first_node->next;
			first_node->next = temp->next;
			
			temp->next = new_head->next;
			new_head->next = temp;;
		}
		new_tail->next = first_node->next;
		first_node->next = new_head->next;
		
		return my_head->next;
	}
};