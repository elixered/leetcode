class Solution {
public:
    int m = pow(10,9);
    int dp[1001][3];
    int solve(int s, int n, int eggs)
    {
        if(s>n) return 0;
        if(eggs==0) return m;
        if(dp[n-s+1][eggs]!=-1) return dp[n-s+1][eggs];
        int res = m;
        for(int i=s; i<=n; i++)
        {
            int curr = max(solve(i+1,n,eggs),solve(s,i-1,eggs-1))+1;
            res = min(res,curr);
        }
        return dp[n-s+1][eggs] = res;
    }
    int twoEggDrop(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(1,n,2);
    }
};