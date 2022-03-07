class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid.size();
        for(int i=0; i<m; i++)
        {
            int mx = 0;
            for(int j=0; j<n; j++)
            {
                mx = max(grid[i][j],mx);
                if(grid[i][j]) ans++;
            }
            ans += mx;
        }
        for(int j=0; j<n; j++)
        {
            int mx = 0;
            for(int i=0; i<m; i++)
            {
                mx = max(grid[i][j],mx);
            }
            ans += mx;
        }
        return ans;
    }
};