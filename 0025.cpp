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
	ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode* my_head = new ListNode(0);
		ListNode* group_head = my_head;
		ListNode* group_tail = my_head;
		while (listLength(head) >= k) {
			int times = k;
			group_tail = head;
			while (times -- ) {//完成一组的头插逆置
				ListNode* temp = head;
				head = head->next;
				temp->next = group_head->next;
				group_head->next = temp;
			}
			group_head = group_tail;
		}
		group_tail->next = head;
		return my_head->next;
	}
	int listLength(ListNode* head) {
		ListNode* temp = head;
		int result = 0;
		while (temp) {
			temp = temp->next;
			++ result;
		}
		return result;
	}
};