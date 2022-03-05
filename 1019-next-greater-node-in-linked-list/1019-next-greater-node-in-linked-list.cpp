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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        stack<int> org,st;
        while(head!=NULL)
        {
            org.push(head->val);
            head = head->next;
        }
        st.push(0);
        while(!org.empty())
        {
            auto curr = org.top();
            org.pop();
            while(st.size()>1 && curr>= st.top())
                st.pop();
            ans.push_back(st.top());
            st.push(curr);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};