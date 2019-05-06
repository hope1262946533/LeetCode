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
	ListNode* rotateRight(ListNode* head, int k) {
		int len = 0;
		ListNode* last = getLastItem(head, len);
		
		if (!len || !(k%len) ) {
			return head;
		}
		k %= len;
		
		ListNode* my_head = new ListNode(0);
		ListNode* new_head = findRightItem(head, k);
		
		my_head->next = new_head->next;
		last->next = head;
		new_head->next = nullptr;
		
		return my_head->next;
	}
	
	ListNode* getLastItem(ListNode* head, int &len) {
		ListNode* my_head = new ListNode(0);
		my_head->next = head;
		while (my_head->next) {
			++ len;
			my_head = my_head->next;
		}
		return my_head;
	}
	
	ListNode* findRightItem(ListNode* head, int k) {
		ListNode* current = head;
		ListNode* result = head;
		while (k >= 0) {
			current = current->next;
			-- k;
		}
		while (current) {
			current = current->next;
			result = result->next;
		}
		return result;
	}
};