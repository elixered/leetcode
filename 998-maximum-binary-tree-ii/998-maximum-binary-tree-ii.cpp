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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if(root==NULL)
            return new TreeNode(val);
        if(root->val < val)
        {
            TreeNode* curr = new TreeNode(val);
            curr->left = root;
            return curr;
        }
        else root->right = insertIntoMaxTree(root->right,val);
        return root;
    }
};