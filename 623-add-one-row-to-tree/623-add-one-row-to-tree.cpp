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
    
    void solve(TreeNode* root, int val, int d){
        if(!root) return;
        if(d){
            solve(root->left,val,d-1);
            solve(root->right,val,d-1);
        }
        else{
            auto l = new TreeNode(val);
            l->left = root->left;
            root->left = l;
            auto r = new TreeNode(val);
            r->right = root->right;
            root->right = r;
        }
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            auto node = new TreeNode(val);
            node->left = root;
            return node;
        }
        solve(root,val,depth-2);
        return root;
    }
};