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
    int solve(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        int l = solve(root->left);
        int r = solve(root->right);
        int arrowleft = 0, arrowright = 0;
        if(root->left && root->left->val==root->val)
            l++;
        else l =0;
        if(root->right && root->right->val==root->val)
            r++;
        else r = 0;
        ans = max(ans,l+r);
        return max(l,r);
    }

    int longestUnivaluePath(TreeNode* root) {
        if(root==NULL) return 0;
        solve(root);
        return ans;
    }
};