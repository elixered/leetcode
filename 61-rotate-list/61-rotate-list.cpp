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
    int length(ListNode* head)
    {
        int count = 0;
        while(head && ++count)
            head = head->next;
        return count;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL or head->next==NULL or k==0)
            return head;
        int sz = length(head);
        k = k%sz;
        if(k==0) return head;
        ListNode* right = head;
        ListNode* left = head;
        ListNode* prev = NULL,*left_prev=NULL;
        while(k--)
        {
            prev = right;
            right = right->next;
        }
        while(right)
        {
            prev = right;
            right = right->next;
            left_prev = left;
            left = left->next;
        }
        prev->next = head;
        left_prev->next=NULL;
        return left;
    }
};