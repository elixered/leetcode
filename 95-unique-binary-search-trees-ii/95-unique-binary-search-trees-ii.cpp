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
    vector<TreeNode*> solve(int s, int e)
    {
        vector<TreeNode*> ans;
        if(s>e)
        {
            ans.push_back(NULL);
            return ans;
        }

        for(int i=s; i<=e; i++)
        {
            auto l = solve(s,i-1);
            auto r = solve(i+1,e);
            for(auto j:l)
            {
                for(auto k:r)
                {
                    TreeNode* root = new TreeNode(i);
                    root->left = j;
                    root->right = k;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        return solve(1,n);
    }
};