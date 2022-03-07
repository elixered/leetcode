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
                int curr_pos = i*n+j;
                int next_pos = curr_pos + k;
                int row = (next_pos/n)%m;
                int col = (next_pos%n);
                ans[row][col] = grid[i][j];
            }
        }
        return ans;
    }
};