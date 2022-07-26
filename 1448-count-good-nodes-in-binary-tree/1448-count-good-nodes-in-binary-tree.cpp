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
    
    int solve(TreeNode* root, int m){
        if(!root) return 0;
        int ans = 0;
        if(root->val >= m)
            ++ans;
        ans += solve(root->left,max(root->val,m));
        ans += solve(root->right,max(root->val,m));
        return ans;
    }
    
    int goodNodes(TreeNode* root) {
        return solve(root,root->val);
    }
};