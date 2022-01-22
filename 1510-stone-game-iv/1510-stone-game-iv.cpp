class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<int> dp(n+1,0);
        for(int i=1; i<=n; i++)
        {
            for(int k=1; k*k<=i; k++)
            {
                if(dp[i-k*k]==false)
                    dp[i] = true;
            }
        }
        return dp[n];
    }
};