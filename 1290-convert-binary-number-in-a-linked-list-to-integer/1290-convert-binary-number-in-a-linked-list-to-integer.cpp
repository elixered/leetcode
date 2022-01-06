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
    int solve(ListNode* head, int power)
    {
        if(head==NULL || power<0)
            return 0;

        return head->val*pow(2,power) + solve(head->next,power-1);
    }
    int getDecimalValue(ListNode* head) {
        int count  = 0;
        ListNode* temp = head;
        while(temp)
        {
            count++;
            temp = temp->next;
        }
        return solve(head,count-1);
    }
};