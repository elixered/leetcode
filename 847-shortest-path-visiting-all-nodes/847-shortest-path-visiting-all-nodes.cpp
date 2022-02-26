class Solution {
private:
    int n;
    int memo[15][1<<13];
    vector<vector<int>> g;
    #define maximum 100000;
    int dp(int node, int mask)
    {
        if(memo[node][mask]!=0)
            return memo[node][mask];
        if((mask&(mask-1))==0)
            return 0;
        memo[node][mask] = maximum;
        for(auto it:g[node])
        {
            if((mask&(1<<it))!=0)
            {
                int a = dp(it,mask);
                int b = dp(it,mask^(1<<node));
                int best = min(a,b);
                int curr = memo[node][mask] ;
                memo[node][mask] = min(curr,best+1);
            }
        }
        return memo[node][mask];
    }
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        n = graph.size();
        g = graph;
        int endmask = (1<<n) - 1;
        memset(memo,0,sizeof(memo));
        int ans = maximum;
        for(int i=0; i<n; i++)
            ans = min(ans,dp(i,endmask));
        return ans;
    }
};