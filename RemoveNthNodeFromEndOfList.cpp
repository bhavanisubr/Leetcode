/**
 * Given a linked list, remove the nth node from the end of list and return its head.
 * For example: Given linked list: 1->2->3->4->5, and n = 2.
 * After removing the second node from the end, the linked list becomes 1->2->3->5.
 * 
 * Note: Assume that n will always be valid and try doing this in one pass.
 * 
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       // Method 1
       int length = 0;
       ListNode* temp = head;
       for (; temp->next; ++length)   temp = temp->next;
       temp = head;
       int steps = length - n;
       if (steps < 0) {
          head = temp->next;
          temp->next = NULL;
          return head;
       }
       for (int i = 0; i < steps; i++)   temp = temp->next;
       temp->next = temp->next->next;
       return head;
       
       // Method 2
       /*ListNode* slow = head, *fast = head;
       for (int i = 0; i < n && fast; i++)   fast = fast->next;
       if (!fast) {
          head = slow->next;
          slow->next = NULL;
          return head;
       }
       while (fast->next) {
          fast = fast->next;
          slow = slow->next;
       }
       slow->next = slow->next->next;
       return head;*/
    }
};