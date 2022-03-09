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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head or !head->next) return head;
        ListNode* dummy = new ListNode(-101);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = head;
        ListNode* right = head->next;
        while(right)
        {
            if(curr->val == right->val)
            {
                int val = curr->val;
                while(curr && curr->val==val)
                {
                    ListNode* temp = curr;
                    curr = curr->next;
                    if(right)
                        right = right->next;
                    prev->next = curr;
                    delete temp;
                }
            }
            else
            {
                prev = curr;
                curr = curr->next;
                right = right->next;
            }
        }
        return dummy->next;
    }
};