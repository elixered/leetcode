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
private:
    int ans = 0;
public:
    class info{
        public:
        bool isBST;
        int maxi;
        int mini;
        int maxsum;
        info()
        {
            isBST = true;
            maxi = INT_MIN;
            mini = INT_MAX;
            maxsum = 0;
        }
    };
    info solve(TreeNode* root)
    {
        if(root==NULL)
            return info();
        info i;
        info left = solve(root->left);
        info right = solve(root->right);
        if(left.isBST && right.isBST && root->val > left.maxi && root->val < right.mini)
        {
            i.isBST = true;
            i.maxi = max({root->val,left.maxi,right.maxi});
            i.mini = min({root->val,left.mini,right.mini});
            i.maxsum = left.maxsum+right.maxsum+root->val;
        }
        else
        {
            i.isBST= false;
            i.maxsum = 0;
        }
        ans = max(ans,i.maxsum);
        return i;
    }
    int maxSumBST(TreeNode* root) {
        ans = INT_MIN;
        solve(root);
        return ans>0 ? ans:0;
    }
};