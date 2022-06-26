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
    vector<int> ans;
    
    void dfs(TreeNode* root, int level){
        if(!root) return;
        if(level == ans.size())
            ans.push_back(root->val);
        else
            ans[level] = max(root->val,ans[level]);
        dfs(root->left,level+1);
        dfs(root->right,level+1);
    }
    
    vector<int> largestValues(TreeNode* root) {
        dfs(root,0);
        return ans;
    }
};