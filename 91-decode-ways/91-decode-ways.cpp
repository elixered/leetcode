class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1);
        dp[0] = 1;
        dp[1] = 1;
        if(s[0]=='0') return 0;
        for(int i=2; i<=n; i++)
        {
            int way1=0,way2=0;
            if(s[i-1]!='0') way1 = dp[i-1];
            if(s[i-2]=='1' || (s[i-2]=='2' && s[i-1]<'7'))
                way2 = dp[i-2];
            dp[i] = way1+way2;
        }
        return dp[n];
    }
};