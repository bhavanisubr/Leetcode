/**
 * Write a program to find the node at which the intersection of two singly linked lists begins.
 * For example, the following two linked lists begin to intersect at node c1:

A:          a1 ? a2
                   ?
                     c1 ? c2 ? c3
                   ?            
B:     b1 ? b2 ? b3

 * Notes:
 * If the two linked lists have no intersection at all, return null.
 * The linked lists must retain their original structure after the function returns.
 * You may assume there are no cycles anywhere in the entire linked structure.
 * Your code should preferably run in O(n) time and use only O(1) memory.
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       if (!headA || !headB)   return NULL;
       
       int lengthA = 0, lengthB = 0;
       for (ListNode* tempA = headA; tempA; tempA = tempA->next)   ++lengthA;
       for (ListNode* tempB = headB; tempB; tempB = tempB->next)   ++lengthB;
       
       int diff = abs(lengthA - lengthB);
       for (int i = 0; i < diff; i++)   lengthA > lengthB ? headA = headA->next : headB = headB->next;
       while (headA && headB) {
          if (headA == headB)   return headA;
          headA = headA->next;
          headB = headB->next;
       }
       return NULL;
    }
};