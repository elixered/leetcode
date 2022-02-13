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
    TreeNode* bstToGst(TreeNode* root) {
        if(root==NULL) return root;
        stack<TreeNode*> stack;
        TreeNode* curr = root;
        int sum = 0;
        while(!stack.empty() or curr)
        {
            while(curr)
            {
                stack.push(curr);
                curr = curr->right;
            }
            curr = stack.top();
            stack.pop();
            int x = curr->val;
            curr->val += sum;
            sum += x;
            curr = curr->left;
        }
        
        return root;
    }
};