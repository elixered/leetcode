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
    void dfs(TreeNode* root,TreeNode* prev, int curr, int k,unordered_map<TreeNode*,TreeNode*> &parent)
    {
        if(root==NULL) return;
        if(curr==k)
            ans.push_back(root->val);
        if(curr>k) return;
        if(root->left!=prev)
        dfs(root->left,root,curr+1,k,parent);
        if(root->right!=prev)
        dfs(root->right,root,curr+1,k,parent);
        if(parent[root]!=prev)
        dfs(parent[root],root,curr+1,k,parent);
    }
    void getParents(TreeNode* root, unordered_map<TreeNode*,TreeNode*> &parent)
    {
        if(root==NULL)
            return;
        if(root->left)
        {
            parent[root->left] = root;
            getParents(root->left,parent);
        }
        if(root->right)
        {
            parent[root->right] = root;
            getParents(root->right,parent);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent;
        parent[root] = NULL;
        getParents(root,parent);
        dfs(target,NULL,0,k,parent);
        return ans;
    }
};