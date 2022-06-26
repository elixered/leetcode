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
    
    bool isLeaf(TreeNode* node){
        return !node->left && !node->right;
    }
    
    void getLeftBoundary(TreeNode* root){
        if(!root or isLeaf(root)) return;
        ans.push_back(root->val);
        if(root->left)
            getLeftBoundary(root->left);
        else if(root->right)
            getLeftBoundary(root->right);
    }
    
    void getRightBoundary(TreeNode* root){
        if(!root or isLeaf(root)) return;
        if(root->right)
            getRightBoundary(root->right);
        else if(root->left)
            getRightBoundary(root->left);
        ans.push_back(root->val);
    }
    
    void getLeaves(TreeNode* root){
        if(!root) return;
        getLeaves(root->left);
        if(isLeaf(root)) ans.push_back(root->val);
        getLeaves(root->right);
    }
    
    vector<int> ans;
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if(!root) return ans;
        ans.push_back(root->val);
        getLeftBoundary(root->left);
        getLeaves(root->left);
        getLeaves(root->right);
        getRightBoundary(root->right);
        return ans;
    }
};