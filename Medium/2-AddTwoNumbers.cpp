/**
 * Question: 2. Add Two Numbers
 * 
 * Author Yifan Yuan
 * Date 2022-03-12
 * Description: 
 * You are given two non-empty linked lists representing two non-negative integers. 
 * The digits are stored in reverse order, and each of their nodes contains a single digit.
 * Add the two numbers and return the sum as a linked list. 
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 * 
 * Input:  (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: (7 -> 0 -> 8)
 * 
 * Source: https://leetcode.com/problems/add-two-numbers/
 */

// Iteration
// Definition for singly-linked list.

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int c = 0; //carry bit
        ListNode add(0);
        ListNode *p = &add;
        
        while (c || l1 || l2) {
            c += (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            p->next = new ListNode(c%10);
            p = p->next;
            c /= 10;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        return add.next;
    }
};

//Recursion
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        if (!l1 && !l2) return NULL; //check if l1 and l2 are null or not
        
        int c = (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
        ListNode *add = new ListNode(c%10);
        ListNode *next = l1 ? l1->next:NULL;
        c /= 10;
        if(next) next->val += c;
        else if (c) next = new ListNode(c);
        add->next = addTwoNumbers(l2 ? l2->next:NULL, next);
        return add;
    }
};