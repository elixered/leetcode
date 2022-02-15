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
    void inorder(TreeNode* root, vector<int>& nums)
    {
        if(root)
        {
            inorder(root->left,nums);
            nums.push_back(root->val);
            inorder(root->right,nums);
        }
    }
    TreeNode* bst(vector<int>& nums, int start, int end)
    {
        if(start>end) return NULL;
        else if(start==end)
            return new TreeNode(nums[start]);
        else if(start<end)
        {
            int mid = start + (end-start)/2;
            TreeNode* root = new TreeNode(nums[mid]);
            root->left = bst(nums,start,mid-1);
            root->right = bst(nums,mid+1,end);
            return root;
        } else
        return NULL;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> nums;
        inorder(root,nums);
        return bst(nums,0,nums.size()-1);
    }
};