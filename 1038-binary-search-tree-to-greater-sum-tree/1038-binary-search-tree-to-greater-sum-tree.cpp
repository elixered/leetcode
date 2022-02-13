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
        int sum = 0;
    TreeNode* bstToGst(TreeNode* root) {
        if(root==NULL)
            return root;
        root->right = bstToGst(root->right);
        int x = root->val;
        root->val += sum;
        sum += x;
        root->left = bstToGst(root->left);
        return root;
    }
};