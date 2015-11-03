/**
 * Given a linked list, swap every two adjacent nodes and return its head.
 * 
 * For example: Given 1->2->3->4, you should return the list as 2->1->4->3.
 * 
 * Your algorithm should use only constant space. You may not modify the values in the list, 
 * only nodes itself can be changed.
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
  void swap(ListNode* current, ListNode* next) {
    int temp = current->val;
    current->val = next->val;
    next->val = temp;
  }

  ListNode* swapPairs(ListNode* head) {
    ListNode *current = head, *next = NULL;
    while (current) {   
      next = current->next;
      if (next) {   
        swap(current, next);
        current = next->next;
        continue;
      }   
      break; // current = NULL;
    }   
    return head;
  }
};