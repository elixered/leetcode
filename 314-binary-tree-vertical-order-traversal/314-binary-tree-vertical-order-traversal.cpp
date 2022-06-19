class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        map<int,vector<int>> mp;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            auto node = q.front().first;
            auto col = q.front().second;
            q.pop();
            mp[col].push_back(node->val);
            if(node->left)
                q.push({node->left,col-1});
            if(node->right)
                q.push({node->right,col+1});
        }
        for(auto it:mp)
            ans.push_back(it.second);
        return ans;
    }
};