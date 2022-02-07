class Solution {
public:
    int memo[21][31];
    bool solve(string& s, string& p, int i, int j)
    {
        if(i<0 and j<0) return true;
        else if(j<0) return false;
        else if(i<0)
            return p[j]=='*' && (solve(s,p,i,j-2));
        if(memo[i][j]!=-1) return memo[i][j];
        bool ans = false;
        if(s[i]==p[j] or p[j]=='.') ans = solve(s,p,i-1,j-1);
        else if(p[j]=='*')
        {
            if(j>0 && (p[j-1]==s[i] or p[j-1]=='.'))
            ans = solve(s,p,i-1,j) or solve(s,p,i,j-2);
            else ans = solve(s,p,i,j-2);
        }
        return memo[i][j] = ans;
    }
    
    bool isMatch(string s, string p) {
        memset(memo,-1,sizeof(memo));
        return solve(s,p,s.size()-1,p.size()-1);
    }
};