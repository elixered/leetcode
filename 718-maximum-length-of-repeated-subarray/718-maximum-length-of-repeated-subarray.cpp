class Solution {
public:
    int ans = 0;
    int dp[1001][1001];
    int solve(vector<int>& nums1, vector<int>& nums2, int m, int n)
    {
        if(m==0 or n==0) return 0;
        if(dp[m][n]!=-1) return dp[m][n];
        {
            solve(nums1,nums2,m-1,n);
            solve(nums1,nums2,m,n-1);
        }
        dp[m][n] = nums1[m-1]==nums2[n-1] ? solve(nums1,nums2,m-1,n-1)+1:0;
        ans = max(ans,dp[m][n]);
        return dp[m][n];
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof(dp));
        solve(nums1,nums2,nums1.size(),nums2.size());
        return ans;
    }
};