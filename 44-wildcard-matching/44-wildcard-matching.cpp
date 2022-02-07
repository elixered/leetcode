class Solution {
public:
    vector<vector<int>> memo;
    bool solve(string& s, string& p, int i, int j)
    {
        if(i<0 && j<0) return true;
        else
        if(j<0) return false;
        else
        if(i<0)
            return (p[j]=='*' && solve(s,p,i,j-1));
        if(memo[i][j]!=-1) return memo[i][j];
        bool ans = false;
        if(s[i]==p[j] or p[j]=='?')
            ans = ans or solve(s,p,i-1,j-1);
        else if(p[j]=='*')
            ans = ans or solve(s,p,i,j-1) or solve(s,p,i-1,j);
        return memo[i][j] = ans;            
    }
    
    bool isMatch(string s, string p) {
        memo = vector<vector<int>>(s.size(),vector<int>(p.size(),-1));
        return solve(s,p,s.size()-1,p.size()-1);
    }
};