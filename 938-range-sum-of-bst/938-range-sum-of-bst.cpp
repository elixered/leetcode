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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int s = 0;
        if(root==NULL) return s;
        stack<TreeNode*> st;
        while(!st.empty() or root)
        {
            while(root)
            {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            if(root->val>=low && root->val<=high )
                s += root->val;
            else if(root->val>high) break;
            root = root->right;
        }
        return s;
    }
};