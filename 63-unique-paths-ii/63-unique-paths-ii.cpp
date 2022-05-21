class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> prev(n+1,0);
        prev[1] = 1;
        for(int i=1; i<=m; i++)
        {
            vector<int> curr(n+1,0);
            for(int j=1; j<=n; j++)
            {
                if(obstacleGrid[i-1][j-1]==1)
                    curr[j] = 0;
                else
                    curr[j] = prev[j]+curr[j-1];
            }
            prev = curr;
        }
        return prev[n];
    }
};