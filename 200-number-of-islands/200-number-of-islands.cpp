class Solution {
public:
    int count = 0;
    int m,n;
    void dfs(int i, int j, vector<vector<char>>& grid)
    {
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]!='1')
            return;
        grid[i][j] = '2';
        dfs(i+1,j,grid);
        dfs(i-1,j,grid);
        dfs(i,j+1,grid);
        dfs(i,j-1,grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]=='1')
                {
                    count++;
                    dfs(i,j,grid);
                }
            }
        }
        return count;
    }
};