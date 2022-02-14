class Solution {
public:
    int ans = INT_MAX;
    int prev = -1;
    void solve(TreeNode* root)
    {
        if(root==NULL) return;
        solve(root->left);
        if(prev!=-1)
        ans = min(ans,abs(root->val-prev));
        prev = root->val;
        solve(root->right);
    }
    int minDiffInBST(TreeNode* root) {
        solve(root);
        return ans;
    }
};