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
    int maxLevelSum(TreeNode* root) {
        int level = 0;
        int maxsum = INT_MIN;
        int ans = 0;
        if(root==NULL) return 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int sz = q.size();
            int currsum = 0;
            level++;
            while(sz--)
            {
                auto node = q.front();
                q.pop();
                currsum += node->val;
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            if(currsum>maxsum)
            {
                maxsum = currsum;
                ans = level;
            }
        }
        return ans;
    }
};