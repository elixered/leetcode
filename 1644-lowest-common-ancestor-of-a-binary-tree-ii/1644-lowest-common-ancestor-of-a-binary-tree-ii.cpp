class Solution {
public:
    
    bool foundp = false, foundq = false;
    
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==NULL)
            return NULL;
        
       
        
        TreeNode* leftLCA = lca(root->left, p, q);
        TreeNode* rightLCA = lca(root->right, p, q);
        
         if(root== p || root == q){
            if(root ==p && !foundp){
                foundp = true;
            }
            else if(root==q && !foundq){
                foundq= true;
            }
            return root;
        }
        
        if(leftLCA && rightLCA)
            return root;
        else if(leftLCA)
            return leftLCA;
        else
            return rightLCA;
        
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        auto ans =  lca(root,p,q);
        if(foundp && foundq) return ans;
        else return NULL;
    }
};