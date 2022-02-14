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
    int maxsum = INT_MIN;
    int solve(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        int lsum = solve(root->left);
        int rsum = solve(root->right);
        int val = root->val;
        int curr = max({lsum+rsum+val,max(lsum,rsum)+val,val});
        maxsum = max(maxsum,curr);
        return max(max(lsum,rsum)+val,val);
    }
    int maxPathSum(TreeNode* root) {
         solve(root);
        return maxsum;
    }
};