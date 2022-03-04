class Solution {
public:
    
    int m = pow(10,9);
    int dp[10001][101];
    int solve(int n, int eggs)
    {
        if(n<=1) return n;
        if(eggs==1) return n;
        if(dp[n][eggs]!=-1) return dp[n][eggs];
        int res = m;
        int low = 1;
        int high = n;
        while(low<=high)
        {
            int mid = (high+low)/2;
            int left = solve(mid-1,eggs-1);
            int right = solve(n-mid,eggs);
            res = min(res,max(left,right)+1);
            if(left<right) low = mid+1;
            else high = mid-1;
        }
        return dp[n][eggs] = res;
    }
    
    int superEggDrop(int k, int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n,k);
    }
};