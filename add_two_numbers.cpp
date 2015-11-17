/**
 * You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order
 * and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8)
 *
 * Definition for a singly-linked list:
 * struct ListNode {
 *   int val;
 *   ListNode* next;
 *   ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if (!l1 && !l2)  return NULL;
    if (!l1 || !l2)  return l1 ? l1 : l2;
    int carry = 0;
    ListNode* res = new ListNode(0);
    ListNode* temp = res;
    while (l1 && l2) {
      int sum = carry + l1->val + l2->val;
      carry = sum / 10;
      temp->val = sum % 10;
      l1 = l1->next;
      l2 = l2->next;
      if (l1 || l2) {
        temp->next = new ListNode(0);
        temp = temp->next;
      }
    }
    while (l1) {
      int sum = carry + l1->val;
      carry = sum / 10;
      temp->val = sum % 10;
      l1 = l1->next;
      if (l1) {
        temp->next = new ListNode(0);
        temp = temp->next;
      }
    }
    while (l2) {
      int sum = carry + l2->val;
      carry = sum / 10;
      temp->val = sum % 10;
      l2 = l2->next;
      if (l2) {
        temp->next = new ListNode(0); 
        temp = temp->next;
      }
    }
    if (carry)  temp->next = new ListNode(carry);
    return res;
  }
};
