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
    unordered_map<int,vector<TreeNode*>> map;
    vector<TreeNode*> solve(int n)
    {
        if(n==0) return {NULL};
        if(n==1) return {new TreeNode(0)};
        if(map.find(n)!=map.end()) return map[n];
        vector<TreeNode*> ans;
        n--;
        for(int i=1; i<=n; i+=2)
        {
            auto l = solve(i);
            auto r = solve(n-i);
            for(auto itl:l)
            {
                for(auto itr:r)
                {
                    TreeNode* root = new TreeNode(0);
                    root->left = itl;
                    root->right = itr;
                    ans.push_back(root);
                }
            }
        }
        return map[n] = ans;
    }
    
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*> ans;
        if(n%2==0) return ans;
        return solve(n);
    }
};