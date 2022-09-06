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
    TreeNode* pruneTree(TreeNode* root) {
        if(!root) return root;
        auto l = pruneTree(root->left);
        auto r = pruneTree(root->right);
        if(!l) root->left = NULL;
        if(!r) root->right = NULL;
        if(!l && !r && root->val != 1)
            root = NULL;
        return root;
    }
};