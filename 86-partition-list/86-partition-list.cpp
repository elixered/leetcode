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
    ListNode* partition(ListNode* head, int x) {
        ListNode* before = new ListNode(-1);
        ListNode* after = new ListNode(-1);
        ListNode* headb = before, *heada=after;
        while(head)
        {
            if(head->val<x)
            {
                before->next = new ListNode(head->val);
                before = before->next;
            }
            else
            {
                after->next = new ListNode(head->val);
                after = after->next;
            }
            head = head->next;
        }
        before->next = heada->next;
        return headb->next;
    }
};