class Solution {
public:
    int m, n;
    int dp[72][5000];
    int solve(vector<vector<int>>& mat, int row, int sum, const int& target)
    {
		// Base condition
        if(row == m)
        {
            return abs(sum - target);
        }
        
		// Check if already calculated
        if(dp[row][sum] != -1) return dp[row][sum];
        
        int minDiff = INT_MAX;
        for(int i=0; i<n; i++)
        {
            minDiff = min(minDiff, solve(mat, row+1, sum+mat[row][i], target));
            if(minDiff == 0) break;
        }
        return dp[row][sum] = minDiff;
    }
    
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        m = mat.size();
        n = mat[0].size();
        memset(dp, -1, sizeof(dp));
        return solve(mat, 0, 0, target);;
    }
};