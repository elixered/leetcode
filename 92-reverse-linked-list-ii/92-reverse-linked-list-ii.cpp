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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head or !head->next || left==right)
            return head;
        ListNode *prev = NULL;
        ListNode *curr = head;
        int count = 1;
        while(count<left)
        {
            prev = curr;
            curr = curr->next;
            count++;
        }
        ListNode* attachItToEnd = curr;
        ListNode* attachItToStart = prev;
        for(int i=0; i<=right-left; i++)
        {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        attachItToEnd->next = curr;
        if(attachItToStart)
        attachItToStart->next = prev;
        else
            head = prev;
        return head;
    }
};