class Solution {
public:
    double ans = 0;
    vector<double> psum;
    vector<vector<double>> dp;
    double solve(vector<int>& nums, int k, int idx)
    {
        int n = nums.size();
        if(idx >= n) return (double)0;
        if(dp[idx][k]>0) return dp[idx][k];
        double res = ((psum[n-1]-(idx>0?psum[idx-1]:0))/(n-idx));
        if(k==1) return dp[idx][k] = res;
        double curr = 0;
        
        for(int i=idx; i<n; i++)
        {
            curr += (double)nums[i];
            double avg = curr/(i-idx+1);
            res = max(res,solve(nums,k-1,i+1)+avg);
        }
        ans = max(ans,res);
        return dp[idx][k] = res;
    }
    
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n = nums.size();
        dp = vector<vector<double>>(n+1,vector<double>(k+1,-1.0));
        for(auto i:nums)
            psum.push_back((double)i);
        for(int i=1; i<n; i++)
            psum[i] += psum[i-1];
        solve(nums,k, 0);
        return dp[0][k];
    }
};