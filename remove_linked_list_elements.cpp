/**
 * Remove all elements from a linked list of integers that have value val.
 * Example: Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6 and val = 6, return: 
 * 1 --> 2 --> 3 --> 4 --> 5
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
  ListNode* removeElements(ListNode* head, int val) {
    ListNode* slow = head, *fast = head;
    while (fast) {
      while (fast && fast->val != val)  fast = fast->next;
      if (!fast)  break;
      if (fast == head) {
        head = fast->next;
        fast = head;
        continue;
      }
      while (slow->next != fast)  slow = slow->next;
      slow->next = fast->next;
      fast = slow->next;
    }
    return head;
  }
};
