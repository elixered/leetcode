/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> ans;
    unordered_map<TreeNode*,TreeNode*> map;
    void dfs(TreeNode* root,TreeNode* prev, int curr, int k)
    {
        if(root==NULL) return;
        if(curr==k)
            ans.push_back(root->val);
        if(curr>k) return;
        if(root->left!=prev)
        dfs(root->left,root,curr+1,k);
        if(root->right!=prev)
        dfs(root->right,root,curr+1,k);
        if(map[root]!=prev)
        dfs(map[root],root,curr+1,k);
    }
    void level(TreeNode* root, TreeNode* par,TreeNode* target, int curr)
    {
        if(root==NULL) return;
        map[root] = par;
        level(root->left,root,target,curr+1);
        level(root->right,root,target,curr+1);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map[root] = NULL;
        level(root,NULL,target,0);
        dfs(target,NULL,0,k);
        return ans;
    }
};