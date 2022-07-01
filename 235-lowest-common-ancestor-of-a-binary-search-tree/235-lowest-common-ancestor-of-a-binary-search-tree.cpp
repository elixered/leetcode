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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        if(root == p or root == q) return root;
        TreeNode* l = NULL;
        if(p->val < root->val or q->val < root->val)
        l = lowestCommonAncestor(root->left,p,q);
        TreeNode* r = NULL; 
        if(p->val > root->val or q->val > root->val)
        r = lowestCommonAncestor(root->right,p,q);
        if(l==NULL && r==NULL)
            return NULL;
        else if(l && r) return root;
        else if(l)
            return l;
        else return r;
    }
};