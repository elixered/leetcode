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
    unordered_map<int,int> map;
    int count = 0;
    void solve(TreeNode* root, int target, int curr)
    {
        if(root==NULL)
            return;
        curr += root->val;
        count += map[curr-target];
        map[curr]++;
        solve(root->left,target,curr);
        solve(root->right,target,curr);
        map[curr]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        map[0] = 1;
        solve(root,targetSum,0);
        return count;
    }
};