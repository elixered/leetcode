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
    
    class node{
    public:
        int mx, mn, sz;
        node(int a, int b, int c){
            mx = a;
            mn = b;
            sz = c;
        }
    };
    
    node solve(TreeNode* root){
        if(!root)
            return node(INT_MIN,INT_MAX,0);
        auto l = solve(root->left);
        auto r = solve(root->right);
        
        if(l.mx < root->val && root->val < r.mn){
            return node(max(root->val,r.mx), min(root->val,l.mn),l.sz+r.sz+1);
        }
        else return node(INT_MAX,INT_MIN,max(l.sz,r.sz));
    }
    
    int largestBSTSubtree(TreeNode* root) {
        return solve(root).sz;
    }
};