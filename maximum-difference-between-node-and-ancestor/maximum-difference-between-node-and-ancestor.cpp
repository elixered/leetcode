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
    vector<int> solve(TreeNode* root)
    {
        if(!root)
            return {};
        vector<int> left,right;
        if(root->left)
            left = solve(root->left);
        if(root->right)
            right = solve(root->right);
        int mini = root->val, maxi = root->val;
        if(left.size()!=0)
        {
            mini = min(left[0],mini);
            maxi = max(left[1],maxi);
        }
        if(right.size()!=0)
        {
            mini = min(right[0],mini);
            maxi = max(right[1],maxi);
        }
        ans = max(ans,abs(root->val-mini));
        ans = max(ans,abs(root->val-maxi));
        return {mini,maxi};
    }
    int maxAncestorDiff(TreeNode* root) {
        solve(root);
        return ans;
    }
};