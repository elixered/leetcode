class Solution {
public:
    vector<vector<int>> g;
    
    void dfs(vector<int>& v, vector<int>& quiet, int curr, int& mini)
    {
        if(v[curr]) return;
        v[curr] = 1;
        if(quiet[curr]<quiet[mini])
            mini = curr;
        for(auto nb:g[curr])
            dfs(v,quiet,nb,mini);
    }
    
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        g = vector<vector<int>>(n);
        for(auto& it:richer)
        {
            g[it[1]].push_back(it[0]);
        }
        vector<int> ans(n);
        for(int i=0; i<n; i++)
        {
            int mini = i;
            vector<int> v(n,0);
            dfs(v,quiet,i,mini);
            ans[i] = mini;
        }
        return ans;
    }
};