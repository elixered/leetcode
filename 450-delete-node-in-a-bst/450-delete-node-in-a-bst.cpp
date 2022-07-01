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
    
    TreeNode* getMax(TreeNode* root){
        TreeNode* par = NULL;
        while(root->right){
            par = root;
            root = root->right;
        }
        return par;
    }
    
    TreeNode* getMin(TreeNode* root){
        TreeNode* par = NULL;
        while(root->left){
            par = root;
            root = root->left;
        }
        return par;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        if(key < root->val){
            root->left = deleteNode(root->left,key);
        }
        else if(key > root->val){
            root->right = deleteNode(root->right,key);
        }
        else{
            if(root->left){
                auto par = getMax(root->left);
                if(par == NULL){
                    root->val = root->left->val;
                    root->left = root->left->left;
                }
                else{
                    root->val = par->right->val;
                    par->right = par->right->left;
                }
            }
            else if(root->right){
                auto par = getMin(root->right);
                if(par == NULL){
                    root->val = root->right->val;
                    root->right = root->right->right;
                }
                else{
                    root->val = par->left->val;
                    par->left = par->left->right;
                }
            }
            else{
                root = NULL;
            }
        }
        return root;
    }
};