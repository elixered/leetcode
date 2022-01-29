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
    ListNode* sortList(ListNode* head) {
        if(!head or !head->next)
            return head;
        ListNode *mid = getMid(head);
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);
        return merge(left,right);
    }
    ListNode* getMid(ListNode* head)
    {
        ListNode *midPrev = NULL;
        while(head and head->next)
        {
            midPrev = (midPrev==NULL)?head:midPrev->next;
            head = head->next->next;
        }
        ListNode *mid = midPrev->next;
        midPrev->next = NULL;
        return mid;
    }
    ListNode* merge(ListNode* left, ListNode* right)
    {
        ListNode *dummy = new ListNode(0), *dummyHead = dummy;
        while(left && right)
        {
            if(left->val<right->val)
            {
                dummy->next = new ListNode(left->val);
                left = left->next;
            }
            else
            {
                dummy->next = new ListNode(right->val);
                right = right->next;
            }
            dummy = dummy->next;
        }
        while(left)
        {
            dummy->next = new ListNode(left->val);
            left = left->next;
            dummy = dummy->next;
        }
        while(right)
        {
            dummy->next = new ListNode(right->val);
            right = right->next;
            dummy = dummy->next;
        }
        return dummyHead->next;
    }
};