/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
         if(head==NULL or head->next==NULL)
            return false;
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast)
                break;
        }
        if(fast==NULL or fast->next==NULL)
            return false;
        return true;
    }
};