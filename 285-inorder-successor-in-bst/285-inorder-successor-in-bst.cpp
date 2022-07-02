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
    
    
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(!root) return NULL;
        auto l = inorderSuccessor(root->left,p);
        if(l) return l;
        if(root->val > p->val) return root;
        auto r = inorderSuccessor(root->right,p);
        return r;
    }
};