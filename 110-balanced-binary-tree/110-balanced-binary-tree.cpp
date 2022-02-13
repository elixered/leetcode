class Solution {
public:
    int check(TreeNode *root)
    {
        if(root==NULL)
            return 0;
        else
            return max(check(root->left),check(root->right))+1;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
            return true;
        if(abs(check(root->left)-check(root->right))>1)
            return false;
        else
            return isBalanced(root->left) && isBalanced(root->right);
    }
};