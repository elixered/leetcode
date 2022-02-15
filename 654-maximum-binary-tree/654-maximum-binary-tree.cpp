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
    TreeNode* build(vector<int>& nums, int s, int e)
    {
        if(s>e) return NULL;
        if(s==e) return new TreeNode(nums[s]);
        int idx = s;
        for(int i=s; i<=e; i++)
        {
            if(nums[i]>nums[idx])
                idx = i;
        }
        TreeNode* root = new TreeNode(nums[idx]);
        root->left = build(nums,s,idx-1);
        root->right = build(nums,idx+1,e);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(nums,0,nums.size()-1);
    }
};