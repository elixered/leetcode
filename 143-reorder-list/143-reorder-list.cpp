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
    void reorderList(ListNode* head) {
        if(!head or !head->next)
            return;
        vector<ListNode*> vec;
        ListNode* temp = head;
        while(temp!=NULL)
        {
            vec.push_back(temp);
            temp = temp->next;
        }
        int i=0,j=vec.size()-1;
        while(i<j-1)
        {
            ListNode* last = vec[j];
            ListNode* prev_last = vec[j-1];
            ListNode *first = vec[i];
            ListNode *next = vec[i+1];
            first->next = last;
            last->next = next;
            prev_last->next = NULL;
            i++;
            j--;
        }
        return;
    }
};