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
    unordered_set<int> st;
    
    TreeNode* lca(TreeNode* root){
        if(!root or st.count(root->val)) return root;
        auto l = lca(root->left);
        auto r = lca(root->right);
        if(l && r) return root;
        else return l ? l:r;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        for(auto& node:nodes)
            st.insert(node->val);
        return lca(root);
    }
};