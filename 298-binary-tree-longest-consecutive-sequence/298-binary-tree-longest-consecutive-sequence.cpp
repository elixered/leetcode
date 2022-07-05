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
    
    void solve(TreeNode* root, int curr){
        if(!root) return;
        ans = max(ans,curr);
        if(root->left){
            if(root->left->val - root->val == 1)
                solve(root->left,curr+1);
            else
                solve(root->left,1);
        }
        if(root->right){
            if(root->right->val - root->val == 1)
                solve(root->right,curr+1);
            else
                solve(root->right,1);
        }
    }
    
    int longestConsecutive(TreeNode* root) {
        if(!root) return 0;
        solve(root,1);
        return ans;
    }
};