class Solution {
private:
	unordered_map<TreeNode*, int> depth;
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(!root)
            return NULL;
        int l = countDepth(root->left);
        int r = countDepth(root->right);
        if(l == r)
            return root;
        else if(l < r)
            return lcaDeepestLeaves(root->right);
        else
            return lcaDeepestLeaves(root->left);
    }
    
    int countDepth(TreeNode* root){
        if(!root)
            return 0;
        if(!depth.count(root))
            depth[root] = 1 + max(countDepth(root->left), countDepth(root->right));
        return depth[root];
		
    }
};