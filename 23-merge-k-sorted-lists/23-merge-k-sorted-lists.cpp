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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        ListNode* dummy = new ListNode(-1);
        ListNode *dummyHead = dummy;
        bool flag = true;
        while(flag)
        {
            flag = false;
            int mini = INT_MAX;
            int idx = -1;
            for(int i=0; i<n; i++)
            {
                ListNode* temp = lists[i];
                if(temp!=NULL && temp->val<mini)
                {
                    mini = temp->val;
                    idx = i;
                    flag = true;
                }
            }
            if(flag==false) break;
            dummy->next = lists[idx];
            dummy = lists[idx];
            lists[idx] = lists[idx]->next;
        }
        return dummyHead->next;
    }
};