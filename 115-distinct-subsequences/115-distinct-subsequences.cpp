class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<unsigned int> dp(n+1,0);
        dp[0] = 1;
        for(int i=1; i<=m; i++)
        {
            vector<unsigned int> temp(n+1,0);
            for(int j=0; j<=n; j++)
            {
                if(j==0)
                    temp[j] = 1;
                else
                if(s[i-1]==t[j-1])
                    temp[j] = dp[j-1] + dp[j];
                else temp[j] = dp[j];
            }
            dp = temp;
        }
        return dp[n];
    }
};