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
        TreeNode* ans = NULL;
        while(root!=NULL){
            if(p->val >= root->val)
                root = root->right;
            else{
                ans = root;
                root = root->left;
            }
        }
        return ans;
    }
};