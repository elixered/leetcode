class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        int n = nums.size();
        for(auto it:nums)
            sum += it;
        if((sum+target)%2!=0 or abs(target)>sum)
            return 0;
        int total = (sum-target)/2;
        int dp[n+1][total+1];
        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<=total; j++)
            {
                if(i==0)
                    dp[i][j] = 0;
                if(j==0)
                    dp[i][j] = 1;
            }
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=0; j<=total; j++)
            {
                if(nums[i-1]<=j)
                    dp[i][j] = dp[i-1][j]+dp[i-1][j-nums[i-1]];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][total];
    }
};