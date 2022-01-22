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
        if(!head or !head->next) return head;
        ListNode* reversed = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return reversed;
    }
    
    void reorderList(ListNode* head) {
        if(!head or !head->next)
            return;
        ListNode* rt = head, *lt = head,*prev=NULL;
        while(rt && rt->next)
        {
            prev = lt;
            lt = lt->next;
            rt = rt->next->next;
        }
        if(prev)
        prev->next = NULL;
        lt = reverse(lt);
        rt = head;
        while(lt && rt)
        {
            ListNode* temp = lt;
            ListNode* nex = rt->next;
            lt = lt->next;
            rt->next = temp;
            if(nex)
            temp->next = nex;
            rt = nex;
        }
        return;
    }
};