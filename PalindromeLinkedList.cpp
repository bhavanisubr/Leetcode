/**
 * Given a singly linked list, determine if it is a palindrome.
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
    ListNode* reverseLinkedList(ListNode* head) {
      ListNode* prev = NULL, *current = head, *next;
      while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
      }
      return prev;
    }
    
    bool isPalindrome(ListNode* head) {
      ListNode* tempHead = head;
      int length = 0;
      for (; tempHead; tempHead = tempHead->next)  ++length;
      
      ListNode* mid = head;
      for (int i = 0; i < length / 2; i++, mid = mid->next);
      
      if (length % 2)  mid = mid->next;
      mid = reverseLinkedList(mid);
      tempHead = head;
      ListNode* tempMid = mid;
      
      for (int i = 0; i < length / 2; i++, tempHead = tempHead->next, tempMid = tempMid->next) {
        if (tempHead->val != tempMid->val) {
          mid = reverseLinkedList(mid);
          return false;
        }
      }
      mid = reverseLinkedList(mid);
      return true;
    }
};