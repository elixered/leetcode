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
    
    
    vector<TreeNode*> solve(int low, int high)
    {
        vector<TreeNode*> ret;
        if(low>high) 
        {
            ret.push_back(NULL);
            return ret;
        }
        else if(low==high)
        {
            ret.push_back(new TreeNode(low));
            return ret;
        }
        for(int i=low; i<=high; i++)
        {
            vector<TreeNode*> left = solve(low,i-1);
            vector<TreeNode*> right = solve(i+1,high);
            for(auto j:left)
            {
                for(auto k:right)
                {
                    TreeNode* root = new TreeNode(i);
                    root->left = j;
                    root->right = k;
                    ret.push_back(root);
                }
            }
        }
        return ret;
    }
    
    vector<TreeNode*> generateTrees(int n) {     
        
       return solve(1,n);
       
    }
};