class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        
        int m = 1000000007;
        int dp[d+1][target+1];
        memset(dp,0,sizeof dp);
 
        dp[0][0] = 1;
        for(int i=1; i<=d; i++)
        {
            for(int j=1; j<=target; j++)
            {
                for(int k=1; k<=f; k++)
                {
                    if(j>=k)
                        dp[i][j] += dp[i-1][j-k]%m;
                    dp[i][j] %= m;
                }
            }
        }
        
        return dp[d][target];
    }
};