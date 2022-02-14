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
     TreeNode* res,*dummy;
    void solve(TreeNode* root)
    {
        if(root)
        {
            solve(root->left);
            res->right = root;
            res = res->right;
            root->left = NULL;
            solve(root->right);
        }
    }
    TreeNode* increasingBST(TreeNode* root) {
        res = new TreeNode(102), dummy = res;
        if(root==NULL) return root;
        solve(root);
        return dummy->right;
    }
};