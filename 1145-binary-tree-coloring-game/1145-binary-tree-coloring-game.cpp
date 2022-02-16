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
    TreeNode* get(TreeNode* root, int x)
    {
        if(root==NULL) return NULL;
        if(root->val==x)
            return root;
        auto l = get(root->left,x);
        auto r = get(root->right,x);
        if(l) return l;
        else return r;
    }
    int count(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        return count(root->left)+count(root->right)+1;
    }
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        TreeNode* curr = get(root,x);
        int l = count(curr->left);
        int r = count(curr->right);
        int p = n-l-r-1;
        if(p>l+r+1 or l>p+r+1 or r>p+l+1)
            return true;
        else return false;
    }
};