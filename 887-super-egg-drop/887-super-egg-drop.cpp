class Solution {
public:
    int m = pow(10,9);
    int dp[100001][101];
    int solve(int s, int n, int eggs)
    {
        if(s>n) return 0;
        if(eggs==0) return m;
        if(dp[n-s+1][eggs]!=-1) return dp[n-s+1][eggs];
        int res = m;
        int low = s,high = n;
        while(low<=high)
        {
            int i = low + (high-low)/2;
            int left = solve(s,i-1,eggs-1);
            int right = solve(i+1,n,eggs);
            int temp = max(left,right)+1;
            res = min(res,temp);
            if(left<right)
                low = i+1;
            else high = i-1;       
        }
        return dp[n-s+1][eggs] = res;
    }
    int superEggDrop(int k, int n) {
         memset(dp,-1,sizeof(dp));
        return solve(1,n,k);
    }
};