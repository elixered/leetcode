class Solution {
public:
    
    int dp[111][111];
    
    bool solve(string s1, string s2, string s3, int i1, int i2, int i3){
        if(i3<0) return true;
        if(dp[i1+10][i2+10]!=-1) return dp[i1+10][i2+10];
        bool flag = false;
        if(i1>=0 && s1[i1] == s3[i3])
            flag = flag or solve(s1,s2,s3,i1-1,i2,i3-1);
        if(i2>=0 && s2[i2] == s3[i3])
            flag = flag or solve(s1,s2,s3,i1,i2-1,i3-1);
        return dp[i1+10][i2+10] = flag;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        memset(dp,-1,sizeof(dp));
        if(s1.size() + s2.size() != s3.size()) return false;
        return solve(s1,s2,s3,s1.size()-1,s2.size()-1,s3.size()-1);
    }
};