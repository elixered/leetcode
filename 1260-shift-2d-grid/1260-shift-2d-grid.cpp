class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        k = k%(m*n);
        vector<vector<int>> ans(m,vector<int>(n));
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(j+k<n)
                ans[i][j+k] = grid[i][j];
                else
                {
                    int c = (j+k%n)%n;
                    int r = (i+1+(k-n+j)/n)%m;
                    ans[r][c] =  grid[i][j];
                }
            }
        }
        return ans;
    }
};