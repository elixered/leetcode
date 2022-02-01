class Solution {
public:
     int memo[1001][51];
    
    int solve(vector<int>& prefix, int idx, int m)
    {
        int n = prefix.size()-1;
        if(memo[idx][m]!=-1)
            return memo[idx][m];
        if(m==1)
        {
            return memo[idx][m] = prefix[n]-prefix[idx];
        }
        int mini = INT_MAX;
        for(int i=idx; i<=n-m; i++)
        {
            int firstSplitSum = prefix[i+1]-prefix[idx];
            int largest = max(firstSplitSum,solve(prefix,i+1,m-1));
            mini = min(mini,largest);
            if(firstSplitSum >= mini)
                break;
        }
        return memo[idx][m] = mini;
    }
    
    int splitArray(vector<int>& nums, int m) {
          memset(memo, -1, sizeof(memo));
        
        // Store the prefix sum of nums array.
        int n = nums.size();
        vector<int> prefixSum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        
        return solve(prefixSum, 0, m);
    }
};