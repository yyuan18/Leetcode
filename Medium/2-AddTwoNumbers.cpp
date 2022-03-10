// Iteration
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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