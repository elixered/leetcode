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
    
    bool leaf(TreeNode* root){
        return !root->left && !root->right;
    }
    
    int maxheight = 0;
    
    void solve(TreeNode* root, int h){
        if(root == NULL) return;
        maxheight = max(maxheight,h);
        solve(root->left,h+1);
        solve(root->right,h+1);
    }
    
    TreeNode* lcaDeepestLeaves(TreeNode* root,int h = 0) {
        solve(root,0);
        if(!root or (leaf(root) && h == maxheight)) return root;
        auto l = lcaDeepestLeaves(root->left,1+h);
        auto r = lcaDeepestLeaves(root->right,1+h);
        if(l && r) return root;
        return l ? l : r;
    }
};