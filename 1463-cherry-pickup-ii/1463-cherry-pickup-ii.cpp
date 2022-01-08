class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        const int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m+2, vector<vector<int>>(n+2, vector<int>(n+2, 0)));
        //int dp[m+2][n+2][n+2]; memset(dp, 0, sizeof(dp)); // ok
        for(int i = m; i > 0; i--)
            for(int j = 1; j <= n; j++)
                for(int k = 1; k <= n; k++){
                    int tmp = grid[i-1][j-1] + (j!=k)* grid[i-1][k-1];
                    for(int d1 = -1; d1<=1; d1++)
                        for(int d2 = -1; d2<=1; d2++)     dp[i][j][k] = max(dp[i][j][k], tmp +  dp[i+1][j+d1][k+d2]);
                }
        return dp[1][1][n];
    }
};