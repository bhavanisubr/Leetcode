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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1 && l2)  return l2;
        if (l1 && !l2)  return l1;
        if (!l1 && !l2) return NULL;
        ListNode* head = NULL, *tail = NULL;
        while (l1 && l2)
        {
            ListNode* minNode;
            if (l1->val <= l2->val)
            {
                minNode = l1;
                l1 = l1->next;
            }
            else
            {
                minNode = l2;
                l2 = l2->next;
            }
            if (!tail)
            {
                tail = minNode;
                head = minNode;
                continue;
            }
            tail->next = minNode;
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;
        return head;
    }
};