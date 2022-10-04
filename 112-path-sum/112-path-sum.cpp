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
    
    bool solve(TreeNode* root, int sum, int tar)
    {
        if(root==NULL)
            return false;
        sum += root->val;
        if(sum==tar && root->left==NULL && root->right==NULL)
            return true;
        
        
        return solve(root->left,sum,tar) || solve(root->right,sum,tar);
    }
    
    bool hasPathSum(TreeNode* root, int tar) {
        if(root==NULL)  return false;
        int sum = root->val;
        return solve(root,0,tar);
    }
};