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
    void solve(TreeNode* root, string& s, int& ans)
    {
        if(root==NULL)
            return;
        s += to_string(root->val);
        if(root->left==NULL && root->right==NULL)
        {
            int res = 0;
            int n = s.size();
            for(int i=s.size()-1; i>=0; i--)
            {
                if(s[i]=='1')
                res += pow(2,n-i-1);
            }
            ans+=res;
        }
        solve(root->left,s,ans);
        solve(root->right,s,ans);
        s.pop_back();
        return;
    }
    int sumRootToLeaf(TreeNode* root) {
        string s = "";
        int ans = 0;
        solve(root,s,ans);
        return ans;
    }
};