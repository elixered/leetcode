class Solution {
public:
    int lcs(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        
        vector<vector<int>> dp(m+1,vector<int>(n+1));
        
        for(int i=0; i<=m; i++)
        {
            for(int j=0; j<=n; j++)
            {
                if(i==0 || j==0) dp[i][j] = 0;
                else
                {
                    if(text1[i-1]!=text2[j-1])
                        dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                    else dp[i][j] = 1 + dp[i-1][j-1];
                }
            }
        }
        return dp[m][n];
    }
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(s.begin(),s.end());
        return lcs(s,t);
    }
    
    int maxProduct(string s) {
        int n = s.size();
        int ans = 0;
        int sz = 1<<n;
        for(int i=1; i<sz; i++)
        {
            string a,b;
            int x = ~i;
            for(int j=0; j<n; j++)
            {
                if((i&(1<<j))!=0)
                    a.push_back(s[j]);
            }
            for(int j=0; j<n; j++)
            {
                if((x&(1<<j))!=0)
                    b.push_back(s[j]);
            }
            int c1 = longestPalindromeSubseq(a);
            int c2 = longestPalindromeSubseq(b);
            ans = max(ans,c1*c2);
        }
        return ans;
    }
};