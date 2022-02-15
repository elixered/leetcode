class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL)
            return 0;
        int ans = 0;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        while(!q.empty())
        {
            int n = q.size();
            int mmin = q.front().second;
            int s,e;
            for(int i=0; i<n; i++)
            {
                auto it = q.front();
                q.pop();
                if(i==0)
                    s = it.second;
                if(i==n-1)
                    e = it.second;
                if(it.first->left)
                    q.push({it.first->left, 2*(it.second-mmin)+1});
                if(it.first->right)
                    q.push({it.first->right, 2*(it.second-mmin)+2});
            }
            ans = max(ans,e-s+1);
        }
        return ans;
    }
};