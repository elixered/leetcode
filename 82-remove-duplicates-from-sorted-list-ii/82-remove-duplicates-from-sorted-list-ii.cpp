class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode **runner = &head;
        
        if(!head || !head->next)return head;
        
        while(*runner)
        {
            if((*runner)->next && (*runner)->next->val == (*runner)->val)
            {
                ListNode *temp = *runner;
                while(temp && (*runner)->val == temp->val)
                    temp = temp->next;
                
                *runner = temp;
            }
            else
                runner = &((*runner)->next);
        }
        
        return head;
    }
};