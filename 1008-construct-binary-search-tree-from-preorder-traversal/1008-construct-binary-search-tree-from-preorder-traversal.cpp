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
    TreeNode* solve(vector<int>& preorder, int s, int e)
    {
        if(s>e or e>preorder.size()) return NULL;
        TreeNode* root = new TreeNode(preorder[s]);
        if(s==e)
            return root;
        TreeNode *left=NULL,*right=NULL;
        int idx = upper_bound(preorder.begin()+s,preorder.begin()+e+1,root->val) - preorder.begin();
        left = solve(preorder,s+1,idx-1);
        right = solve(preorder,idx,e);
        root->left = left;
        root->right = right;
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return solve(preorder,0,preorder.size()-1);
    }
};