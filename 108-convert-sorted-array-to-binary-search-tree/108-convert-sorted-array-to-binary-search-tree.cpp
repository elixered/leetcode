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
    
    TreeNode* solve(vector<int> nums,int low, int high)
    {
        if(low==high)
            return new TreeNode(nums[low]);
        else if(low<high)
        {
            int mid = (low+high)/2;
            TreeNode* root = new TreeNode(nums[(low+high)/2]);
            root->left = solve(nums,low,mid-1);
            root->right = solve(nums,mid+1,high);
            return root;
        }
        else
            return NULL;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        return solve(nums,0,nums.size()-1);
    }
};