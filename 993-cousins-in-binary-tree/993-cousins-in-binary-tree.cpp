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
    bool isCousins(TreeNode* root, int x, int y) {
        if(root==NULL or root->val==x or root->val==y) return false;
        if(x==y) return true;
        queue<TreeNode*> q;
        q.push(root);
        int par1=-1,par2=-1;
        while(!q.empty())
        {
            int n = q.size();
            for(int i=0; i<n; i++)
            {
                auto it = q.front();
                q.pop();
                if(it->left)
                {
                    q.push(it->left);
                    if(it->left->val == x)
                        par1 = it->val;
                    if(it->left->val==y)
                        par2 = it->val;
                }
                if(it->right)
                {
                    q.push(it->right);
                    if(it->right->val == x)
                        par1 = it->val;
                    if(it->right->val==y)
                        par2 = it->val;
                }
            }
            if(par1==-1 && par2==-1)
                continue;
            else if(par1!=-1 && par2!=-1 && par1!=par2)
                return true;
            else return false;
        }
        return false;
    }
};