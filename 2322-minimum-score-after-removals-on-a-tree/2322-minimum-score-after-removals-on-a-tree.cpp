class Solution {
public:
    int n, t;
    vector<vector<int>> adj;
    vector<int> nums, xs, tin, tout;
    
    void dfs(int u=0, int p=-1) {
        tin[u]=t++;
        xs[u]=nums[u];
        for (int v : adj[u])
            if (v!=p) {
                dfs(v, u);
                xs[u]^=xs[v];
            }
        tout[u]=t++;
    }
    
    bool ia(int u, int v) {
        return tin[u]<=tin[v]&&tout[v]<=tout[u];
    }
    
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        n=nums.size();
        this->nums=nums;
        adj.resize(n);
        for (auto x : edges) {
            int u=x[0], v=x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        t=0;
        xs.resize(n);
        tin.resize(n);
        tout.resize(n);
        //cout << "OK1" << endl;
        dfs();
        //cout << "OK " << endl;
        int ans=INT_MAX;
        for (int i=1; i<n; ++i) {
            for (int j=i+1; j<n; ++j) {
                int u=i, v=j;
                if (ia(u, v)||ia(v, u)) {
                    if (ia(v, u))
                        swap(u, v);
                    int a=xs[v], b=xs[u]^xs[v], c=xs[0]^xs[u];
                    ans=min(ans, max({a, b, c})-min({a, b, c}));
                } else {
                    int a=xs[u], b=xs[v], c=xs[0]^xs[u]^xs[v];
                    ans=min(ans, max({a, b, c})-min({a, b, c}));
                }
            }
        }
        return ans;
    }
};
