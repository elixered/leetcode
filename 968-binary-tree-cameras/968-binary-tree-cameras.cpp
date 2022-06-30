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
    int ans = 0;
    int no_need = 1;
    int cover_me = 2;
    int camera = 3;
    int solve(TreeNode* root){
        if(root == NULL) return no_need;
        int l = solve(root->left);
        int r = solve(root->right);
        if(l == no_need && r == no_need)
            return cover_me;
        else if(l == cover_me or r == cover_me){
            ans++;
            return camera;
        }
        else if(l == camera or r == camera)
            return no_need;
        return cover_me;
    }
    
    int minCameraCover(TreeNode* root) {
        return solve(root) == cover_me?ans+1:ans;
    }
};