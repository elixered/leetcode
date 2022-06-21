class Solution 
{
    public:
    int dp[32768],m,n;
    int dfs(int state)
    {
        if(state==0) return 0;
        if(dp[state]!=INT_MAX) return dp[state];
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(state&(1<<(i*n+j))) // if grid[i][j] is 1
                {
                    int t=state;
                    for(int k=0;k<n;k++) t&=~(1<<(i*n+k)); // set the same row bits to 0
                    for(int k=0;k<m;k++) t&=~(1<<(k*n+j)); // set the same column bits to 0
                    dp[state]=min(dp[state],1+dfs(t));
                }
            }
        }
        return dp[state];
    }
    int removeOnes(vector<vector<int>>& grid) 
    {
        m=grid.size(),n=grid[0].size();
        for(int i=0;i<32768;i++) dp[i]=INT_MAX;
        
        int state=0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(grid[i][j]) state|=1<<(i*n+j); // bit[i*n+j] should be set if grid[i][j]=1

        return dfs(state);
    }
};