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
    ListNode* reverseList(ListNode* head) {
        // Iterative solution:
        /* ListNode* prev = NULL;
        ListNode* current = head;
        ListNode* next;
        while (current != NULL)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev; */

        // Recursive solution:
        if (head == NULL)   return NULL;
        ListNode* rest = head->next;
        if (rest == NULL)   return head;
        rest = reverseList(rest);
        head->next->next = head;
        head->next = NULL;
        return rest;
    }
};