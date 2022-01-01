class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>& nums, int i, int j)
    {
        int n = nums.size();
        if(i > j)
            return 0;
        if(i>=0 && j>=0 && i<n && j<n)
            if(dp[i][j]!=-1)
                return dp[i][j];
        int ans = INT_MIN;
        for(int k=i; k<=j; k++)
        {
            int curr = nums[k];
            if(i-1>=0)
                curr *= nums[i-1];
            if(j+1<nums.size())
                curr *= nums[j+1];
            int res = curr + solve(nums,i,k-1) + solve(nums,k+1,j);
            ans = max(res,ans);
        }
        return dp[i][j] = ans;
    }
    
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        dp = vector<vector<int>>(n,vector<int>(n,-1));
        return solve(nums,0,nums.size()-1);
    }
};