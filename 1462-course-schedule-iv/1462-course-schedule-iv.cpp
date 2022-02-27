class Solution {
    vector<vector<int>>dp;
    bool dfs(unordered_map<int, vector<int>>& mp, int a, int b) {
        
        if (dp[a][b] != -1)
            return dp[a][b];
        
        for (int i = 0; i < mp[a].size(); i++) {
            if (mp[a][i] == b || dfs(mp, mp[a][i], b))
                return dp[a][b] = 1;
        }
        
        return dp[a][b] = 0;
    }
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        
        unordered_map<int, vector<int>>mp;
        
        dp.resize(n, vector<int>(n, -1));
        for (int i = 0; i < prerequisites.size(); i++) {
            mp[prerequisites[i][1]].push_back(prerequisites[i][0]);
            dp[prerequisites[i][1]][prerequisites[i][0]] = 1;
        }
            
        vector<bool>res;
        for (int i = 0; i < queries.size(); i++) {
            bool p = dfs(mp, queries[i][1], queries[i][0]);
            res.push_back(p);
        }
        
        return res;
    }
};