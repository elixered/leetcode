class Solution {
public:
    
    int m = pow(10,9)+7;
    int dp[100001][4][2];
    int solve(int n, int count, int absent){
        if(n==0){
            return 1;
        }
        if(dp[n][count][absent]!=-1) return dp[n][count][absent];
        long long ans = 0;
        ans += solve(n-1,0,absent);
        ans %= m;
        if(!absent)
            ans += solve(n-1,0,true);
        ans %= m;
        if(count < 2)
            ans += solve(n-1,count+1,absent);
        ans %= m;
        return dp[n][count][absent] = ans;
    }
    
    int checkRecord(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n,0,0);
    }
};