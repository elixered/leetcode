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
    
    bool check(int& cnt){
        int t = 0;
        for(int i=1; i<=9; ++i)
            if(cnt&(1<<i))
                ++t;
        return t<2;
    }
    
    int solve(TreeNode* root, int& cnt){
        if(!root) return 0;
        int ans = 0;
        cnt ^= (1<<(root->val));
        ans += solve(root->left,cnt);
        ans += solve(root->right,cnt);
        if(!root->left && !root->right && check(cnt))
            ++ans;
        cnt ^= (1<<(root->val));
        return ans;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        int cnt = 0;
        return solve(root,cnt);
    }
};