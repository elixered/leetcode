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
    TreeNode* solve(vector<int>& preorder, int ps, int pe, vector<int>& inorder, int is, int ie)
    {
        if(ps>pe or is>ie) return NULL;
        TreeNode* root = new TreeNode(preorder[ps]);
        int idx;
        for(int i=is; i<=ie; i++)
        {
            if(inorder[i]==preorder[ps])
            {
                idx = i;
                break;
            }
        }
        int numLeft = idx-is;
        int numRight = ie-idx;
        root->left = solve(preorder, ps+1,ps+numLeft,inorder,is,idx-1);
        root->right = solve(preorder, ps+numLeft+1,pe, inorder,idx+1,ie);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return solve(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    }
};