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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* newhead = new ListNode(-1);
        newhead->next = head;
        ListNode* begin = newhead, *fast=newhead,*slow =newhead;
        for(int i=0; i<k;i++)
        {
            begin = begin->next;
            fast = fast->next;
        }
        while(fast && fast->next)
        {
            slow=slow->next;
            fast = fast->next;
        }
        swap(begin->val,slow->next->val);
        return newhead->next;
    }
};