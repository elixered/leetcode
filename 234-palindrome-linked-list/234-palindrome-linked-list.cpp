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
    ListNode* reverse(ListNode* head)
    {
        if(!head or !head->next)
            return head;
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr)
        {
            ListNode* nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(!head or !head->next)
            return true;
        ListNode* slow = head, *fast = head->next;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* prev = slow;
        slow = slow->next;
        prev->next = NULL;
        slow = reverse(slow);
        fast = head;
        while(slow)
        {
            if(slow->val!=fast->val)
                return false;
            slow = slow->next;
            fast = fast->next;
        }
        return true;
    }
};