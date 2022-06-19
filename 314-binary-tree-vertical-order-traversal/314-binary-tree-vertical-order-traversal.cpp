class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        unordered_map<int,vector<int>> mp;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int mini = INT_MAX, maxi = INT_MIN;
        while(!q.empty()){
            auto node = q.front().first;
            auto col = q.front().second;
            mini = min(mini,col);
            maxi = max(maxi,col);
            q.pop();
            mp[col].push_back(node->val);
            if(node->left)
                q.push({node->left,col-1});
            if(node->right)
                q.push({node->right,col+1});
        }
        ans.resize(maxi-mini+1);
        for(auto it:mp)
            ans[it.first-mini] = it.second;
        return ans;
    }
};