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
    
    bool check(vector<int>& cnt){
        int t = 0;
        for(int i=1; i<=9; ++i)
            if(cnt[i]%2)
                ++t;
        return t<2;
    }
    
    int solve(TreeNode* root, vector<int>& cnt){
        if(!root) return 0;
        int ans = 0;
        cnt[root->val]++;
        ans += solve(root->left,cnt);
        ans += solve(root->right,cnt);
        if(!root->left && !root->right && check(cnt))
            ++ans;
        cnt[root->val]--;
        return ans;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> cnt(10,0);
        return solve(root,cnt);
    }
};