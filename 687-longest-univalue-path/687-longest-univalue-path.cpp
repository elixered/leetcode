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
    int ans = 0;
    int solve(TreeNode* root, int x)
    {
        if(root==NULL or root->val!=x)
            return 0;
        int l = solve(root->left,x);
        int r = solve(root->right,x);
        ans = max(ans,l+r);
        return max(l,r)+1;
    }
    void dfs(TreeNode* root)
    {
        if(!root) return;
        solve(root,root->val);
        dfs(root->left);
        dfs(root->right);
    }
    int longestUnivaluePath(TreeNode* root) {
        if(root==NULL) return 0;
        dfs(root);
        return ans;
    }
};