class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        vector<int> dp(n,0);
        int ans = 0;
        for(int i=1; i<n; i++)
        {
            if(s[i]==')' && s[i-1]=='(')
                dp[i] = (i-2>=0?dp[i-2]:0)+2;
            else if(s[i]==')' && s[i-1]==')')
            {
                int idx = i-1-dp[i-1];
                if(idx>=0 && s[idx]=='(')
                {
                    dp[i] = dp[i-1]+2;
                if(idx-1>=0)
                    dp[i] += dp[idx-1];
                }
            }
            else dp[i] = 0;
            cout<<dp[i]<<" ";
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};