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
        if (!head)	return NULL;
		ListNode* slowPtr = head, *fastPtr = head;
		bool containsDuplicates = false;
		while (fastPtr)
		{
			if (containsDuplicates || (slowPtr->next && slowPtr->val == slowPtr->next->val))
			{
				containsDuplicates = true;
				while (fastPtr && fastPtr->val == slowPtr->val)
					fastPtr = fastPtr->next;
				if (fastPtr)	
				{
					slowPtr = slowPtr->next;
					slowPtr->val = fastPtr->val;
				}
				else	break;
			}
			else
			{
				slowPtr = slowPtr->next;
				fastPtr = fastPtr->next;
			}
		}
		if (slowPtr)	slowPtr->next = NULL;
		return head;
    }
};