class Solution {
public:
    int minSideJumps(vector<int>&v) {
        int n=v.size();
        int mx=10000000;
        vector<vector<int>>dp(n+1,vector<int>(4,mx));
        
        dp[0][1]=1;dp[0][2]=0;dp[0][3]=1;
        for(int i=1;i<n;++i){
           
            
            // continuing the previous lane
            
            if(v[i]!=1)dp[i][1]=dp[i-1][1];
            if(v[i]!=2)dp[i][2]=dp[i-1][2];
            if(v[i]!=3)dp[i][3]=dp[i-1][3];
            
            // jumping from other lane
            
            if(v[i]!=1)
            dp[i][1]=min(dp[i][1],min(dp[i][2]+1,dp[i][3]+1));
            if(v[i]!=2)
            dp[i][2]=min(dp[i][2],min(dp[i][3]+1,dp[i][1]+1));
            if(v[i]!=3)
            dp[i][3]=min(dp[i][3],min(dp[i][1]+1,dp[i][2]+1));
           
        }
        return min(dp[n-1][1],min(dp[n-1][2],dp[n-1][3]));
    }
};