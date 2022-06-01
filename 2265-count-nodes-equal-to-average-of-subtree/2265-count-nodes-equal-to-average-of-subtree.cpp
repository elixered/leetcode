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
    int ans;
    pair<int,int> solve(TreeNode* root)
    {
        if(root==NULL) return {0,0};
        auto l = solve(root->left);
        auto r = solve(root->right);
        int tsum = root->val+l.second+r.second;
        int total = l.first+r.first+1;
        if(tsum/total==root->val) ans++;
        return {total,tsum};
    }
    int averageOfSubtree(TreeNode* root) {
        if(root==NULL) return 0;
        ans = 0;
        solve(root);
        return ans;
    }
};