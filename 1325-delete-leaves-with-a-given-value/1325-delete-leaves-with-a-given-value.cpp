class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(root==NULL) return NULL;
        root->left = removeLeafNodes(root->left,target);
        root->right = removeLeafNodes(root->right,target);
        if(root->left != root->right or root->val!=target)
            return root;
        else return NULL;
    }
};