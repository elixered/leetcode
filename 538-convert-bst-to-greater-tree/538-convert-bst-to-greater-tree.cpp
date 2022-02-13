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
    TreeNode* convertBST(TreeNode* root) {
        if(root==NULL) return root;
        stack<TreeNode*> stack;
        TreeNode* curr = root;
        vector<TreeNode*> ans;
        while(!stack.empty() or curr)
        {
            while(curr)
            {
                stack.push(curr);
                curr = curr->right;
            }
            curr = stack.top();
            stack.pop();
            ans.push_back(curr);
            curr = curr->left;
        }
        for(int i=1; i<ans.size(); i++)
        {
            ans[i]->val += ans[i-1]->val;
        }
        return root;
    }
};