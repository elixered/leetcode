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
    #define ll long long
    long long mod;
    long long total;
    long long prod;
    void dfs(TreeNode* root)
    {
        if(root)
        {
            total += root->val;
            dfs(root->left);
            dfs(root->right);
        }
    }
    long long postorder(TreeNode* root)
    {
        if(root==NULL) return 0;
        ll curr = postorder(root->left) + postorder(root->right) + root->val;
        prod = max(prod,(curr*(total-curr)));
        return curr;
    }
    int maxProduct(TreeNode* root) {
        mod = pow(10,9)+7;
        total = 0;
        dfs(root);
        postorder(root);
        return prod%mod;
    }
};