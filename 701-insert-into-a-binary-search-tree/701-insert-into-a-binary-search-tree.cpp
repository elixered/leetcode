class Solution {
public:
    void solve(TreeNode* curr, int val, TreeNode* prev)
    {
        if(curr==NULL)
        {
            if(prev->right==NULL && val>prev->val)
                prev->right = new TreeNode(val);
            if(!prev->left && val<prev->val)
                prev->left = new TreeNode(val);
            return;
        }
        else if(val<curr->val)
            solve(curr->left,val,curr);
        else solve(curr->right,val,curr);
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL)
            return new TreeNode(val);
        solve(root,val,NULL);
        return root;
    }
};