class Solution {
public:
    int countVowelStrings(int n) {
        int dp[n+1][26];
        memset(dp,0,sizeof(dp));
        string s = "aeiou";
        for(auto c:s)
            dp[1][c-'a'] = 1;
        for(int i=2; i<=n; i++)
        {
            for(auto c:s)
            {
                for(auto curr:s)
                {
                    if(curr<=c)
                        dp[i][curr-'a'] += dp[i-1][c-'a'];
                }
            }
        }
        int ans = 0;
        for(auto c:s)
            ans += dp[n][c-'a'];
        return ans;
    }
};