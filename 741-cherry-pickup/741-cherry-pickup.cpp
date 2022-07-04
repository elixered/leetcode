class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -1)));
        int cherries = memoization(grid, dp, 0, 0, 0, 0);
        return cherries <= 0 ? 0 : cherries;
    }
    
    int memoization(vector<vector<int>> &grid, vector<vector<vector<int>>> &dp, int row1, int col1, int row2, int col2) {
        int n = grid.size();
        if(row1 >= n || row2 >= n || col1 >= n || col2 >= n || grid[row1][col1] == -1 || grid[row2][col2] == -1)
            return -1e9;
        
        if(row1 == n-1 && col1 == n-1) return grid[row1][col1];
        if(dp[row1][col1][col2] != -1) return dp[row1][col1][col2];

        int currSum = grid[row1][col1];
        if(row1 != row2) currSum += grid[row2][col2];
        
        int downdown = memoization(grid, dp, row1+1, col1, row2+1, col2);
        int downright = memoization(grid, dp, row1+1, col1, row2, col2+1);
        int rightdown = memoization(grid, dp, row1, col1+1, row2+1, col2);
        int rightright = memoization(grid, dp, row1, col1+1, row2, col2+1);
        
        return dp[row1][col1][col2] = max(downdown, max(downright, max(rightdown, rightright))) + currSum;
    }
};
