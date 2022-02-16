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
    bool isBST(TreeNode* root,long mini, long maxi)
    {
        if(root==NULL)
            return true;
        long val = root->val;
        bool l = isBST(root->left,mini,min(val,maxi));
        bool r = isBST(root->right,max(mini,val),maxi);
        if(l && r && root->val>mini && root->val<maxi)
            return true;
        else return false;
    }
    bool isValidBST(TreeNode* root) {
        return isBST(root,LONG_MIN,LONG_MAX);
    }
};