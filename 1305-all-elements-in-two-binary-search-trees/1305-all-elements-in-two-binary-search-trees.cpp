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
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
    vector<int> st1, st2;
        vector<int> ans;
            inorder(root1,st1);
            inorder(root2,st2);
        int i=0,j=0;
        while(i<st1.size() and j<st2.size())
        {
            if(st1[i]<st2[j])
            {
                ans.push_back(st1[i++]);
            }
            else ans.push_back(st2[j++]);
        }
        while(i<st1.size())
            ans.push_back(st1[i++]);
        while(j<st2.size())
            ans.push_back(st2[j++]);
        return ans;
    }
};