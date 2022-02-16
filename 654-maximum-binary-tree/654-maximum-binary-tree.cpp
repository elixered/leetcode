/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size()==0) return NULL;
        stack<TreeNode*> st;
        for(auto& it:nums)
        {
            TreeNode* curr = new TreeNode(it);
            while(!st.empty() && st.top()->val<curr->val)
            {
                curr->left = st.top();
                st.pop();
            }
            if(!st.empty())
                st.top()->right = curr;
            st.push(curr);
        }
        while(st.size()>1)
            st.pop();
        return st.top();
    }
};