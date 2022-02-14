class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
         vector<vector<int>> res;
        queue<TreeNode *> q;
        if(root==NULL)
            return res;
        bool leftToRight = true;
        q.push(root);
        {
            while(!q.empty())
            {
                int n = q.size();
                vector<int> temp(n);
                for(int i=0;i<n;i++)
                {
                    TreeNode *curr = q.front();
                    q.pop();
                    int idx;
                    if(leftToRight)
                        idx = i;
                    else
                        idx = n-1-i;
                    temp[idx]=curr->val;
                    if(curr->left)q.push(curr->left);
                    if(curr->right)q.push(curr->right);
                }
                leftToRight = !leftToRight;
                res.push_back(temp);
            }
        }
       
        return res;
    
    }
};