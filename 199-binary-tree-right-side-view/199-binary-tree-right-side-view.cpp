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
    
    void solve(TreeNode* root,int level){
        if(!root) return;
        if(level > ans.size())
            ans.push_back(root->val);
        else
            ans[level-1] = root->val;
        solve(root->left,level+1);
        solve(root->right,level+1);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        solve(root,1);
        return ans;
    }
};