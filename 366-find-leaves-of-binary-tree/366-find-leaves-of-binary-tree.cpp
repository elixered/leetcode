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
    vector<vector<int>> ans;
    
    int dfs(TreeNode* root){
        if(!root) return -1;
        
        int level = max(dfs(root->left),dfs(root->right))+1;
        if(level == ans.size())
            ans.push_back(vector<int>());
        ans[level].push_back(root->val);
        return level;
    }
    
    vector<vector<int>> findLeaves(TreeNode* root) {
        dfs(root);
        return ans;
    }
};