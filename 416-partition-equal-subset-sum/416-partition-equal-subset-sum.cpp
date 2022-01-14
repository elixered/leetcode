class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(auto it:nums)
            sum += it;
        if(sum%2!=0)
            return false;
        sum /= 2;
        bool dp[n+1][sum+1];
        for(int i=0; i<=n; i++)        
        {
            for(int j=0; j<=sum; j++)
            {
                if(i==0)
                    dp[i][j] = false;
                if(j==0)
                    dp[i][j] = true;
            }
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=sum; j++)
            {
                if(nums[i-1]<=j)
                    dp[i][j] = dp[i-1][j] or dp[i-1][j-nums[i-1]];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][sum];
    }
};