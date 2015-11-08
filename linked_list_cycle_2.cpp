/**
 * Given a linked list, return the node where the cycle begins. If there is no cycle, return NULL.
 * 
 * Note: Do not modify the linked list.
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
  ListNode* detectCycle(ListNode* head) {
    ListNode* slow = head, *fast = head;
    while (slow && fast && fast->next) {  
      fast = fast->next->next;
      slow = slow->next;
      if (slow == fast) {
        ListNode* slow2 = head;
        while (slow2 != slow) {
          slow2 = slow2->next;
          slow = slow->next;
        }
        return slow;
      }
    }   
    return NULL;
  }
};
