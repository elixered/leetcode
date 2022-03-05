class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> hm(10001,0);
        for(auto it:nums) hm[it]++;
        vector<int> dp(10001,0);
        dp[1] = hm[1];
        for(int i=2; i<10001; i++)
        {
            dp[i] = max(dp[i-2]+hm[i]*i,dp[i-1]);
        }
        return dp.back();
    }
};