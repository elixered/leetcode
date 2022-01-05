class Solution {
public:
    vector<vector<bool>> dp;
    unordered_map<int,int> memo;
    int ans;
    int solve(string& s, int idx)
    {
        int n = s.size();
        if(memo.find(idx)!=memo.end())
            return memo[idx];
        if(idx >= n)
        {
            return 0;
        }
        int res = n;
        for(int i=idx; i<n; i++)
        {
            if(dp[idx][i]==true)
                res = min(res,solve(s,i+1)+1);
        }
        return memo[idx] = res;
    }
    int minCut(string s) {
        int n = s.size();
        ans = n;
        dp = vector<vector<bool>>(n,vector<bool>(n,false));
        for(int i=0; i<n; i++)
        {
            for(int c=i,r=0; c<n; c++,r++)
            {
                if(r==c)
                    dp[r][c] = true;
                else
                    if(c==r+1)
                        dp[r][c] = (s[r]==s[c]);
                else
                {
                    dp[r][c] = (dp[r+1][c-1] && s[r]==s[c]);
                }
            }
        }
        return solve(s,0)-1;
    }
};