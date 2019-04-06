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
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		ListNode* my_head = new ListNode(0);
		ListNode* tail = my_head;
		
		while (firstNotEmptyIndex(lists) != lists.size()) {
			int index = findMinNodeIndex(lists);
			tail->next = lists[index];
			lists[index] = lists[index]->next;
			tail = tail->next;
		}
		return my_head->next;
	}
	int firstNotEmptyIndex(vector<ListNode*>& lists) {
		for (int i = 0; i < lists.size(); ++ i) {
			if (lists[i]) {
				return i;
			}
		}
		return lists.size();
	}
	int findMinNodeIndex(vector<ListNode*>& lists) {
		int result = firstNotEmptyIndex(lists);
		int temp = lists[result]->val;
		for (int i = result + 1; i < lists.size(); ++ i) {
			if (lists[i] && temp > lists[i]->val) {
				temp = lists[i]->val;
				result = i;
			}
		}
		return result;
	}
	
};