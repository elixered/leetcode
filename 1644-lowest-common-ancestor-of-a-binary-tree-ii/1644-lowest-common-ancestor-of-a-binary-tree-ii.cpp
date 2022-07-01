class Solution {
public:
    
    bool checkIfExists(TreeNode* root, TreeNode* node){
        if(root==NULL || node == NULL)
            return false;
        if(root->val == node->val)
            return true;
        if(checkIfExists(root->left, node) || checkIfExists(root->right, node))
            return true;
        else
            return false;
    }
    
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==NULL)
            return NULL;
        
        if(root== p || root == q)
            return root;
        
        TreeNode* leftLCA = lca(root->left, p, q);
        TreeNode* rightLCA = lca(root->right, p, q);
        
        if(leftLCA && rightLCA)
            return root;
        else if(leftLCA)
            return leftLCA;
        else
            return rightLCA;
        
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(checkIfExists(root, p) && checkIfExists(root, q)){
            return lca(root, p, q);
        }
        else{
            return NULL;
        }
    }
};