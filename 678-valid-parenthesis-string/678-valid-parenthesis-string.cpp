class Solution {
public:
    int dp[101][101][101];
    bool solve(int idx, int l,int r, string s)
    {
        int n = s.size();
        if(r>l) return false;
        if(idx==n) return l==r;
        if(dp[idx][l][r]!=-1) return dp[idx][l][r];
        bool flag = false;
        if(s[idx]=='*')
        {
            flag = flag or solve(idx+1,l+1,r,s);
            flag = flag or solve(idx+1,l,r+1,s);
            flag = flag or solve(idx+1,l,r,s);
        }
        else
            flag = flag or solve(idx+1,l + (s[idx]=='('), r + (s[idx]==')'),s);
        return dp[idx][l][r] = flag;
    }
    bool checkValidString(string s) {
        memset(dp,-1,sizeof(dp));
        int n = s.size();
        return solve(0,0,0,s);
    }
};