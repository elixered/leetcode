class Solution {
public:
    
    int dp[2001][2001];
    
    int solve(vector<vector<int>>& piles, int idx, int k){
        int n = piles.size();
        if(n==idx or k==0) return 0;
        if(dp[idx][k]!=-1) return dp[idx][k];
        int sum = 0;
        int ans = solve(piles,idx+1,k);
        for(int i=0; i<piles[idx].size(); ++i){
            if(k-i-1 < 0) break;
            sum += piles[idx][i];
            ans = max(ans,solve(piles,idx+1,k-i-1)+sum);
        }
        return dp[idx][k] = ans;
    }
    
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(piles,0,k);
    }
};