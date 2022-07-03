int dp[1001][1001] = {};
int m = pow(10,9)+7;
class Solution {
public:
    
    int solve(int n, int k){
        if(k==0) return 1;
        if(n<=1 or k>n) return 0;
        if(dp[n][k]!=0) return dp[n][k];
        int ans = solve(n-1,k);
        for(int len=2; len<=n-k+1; len++){
            ans += solve(n-len+1,k-1);
            ans %= m;
        }
        return dp[n][k] = ans;
    }
    
    int numberOfSets(int n, int k) {
        return solve(n,k);
    }
};