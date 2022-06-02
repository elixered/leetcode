class Solution {
public:
    int ans = 0;
    int m,n;
    vector<int> dir = {-1,0,1,0,-1};
    bool valid(int x, int y)
    {
        return x>=0 && y>=0 && x<m && y<n;
    }
    int dfs(vector<vector<int>>& grid, int r, int c, vector<vector<int>>& vis)
    {
        int curr = 0;
        vis[r][c] = 1;
        for(int i=0; i<4; i++)
        {
            int x = r + dir[i];
            int y = c + dir[i+1];
            if(valid(x,y) && vis[x][y]==0 && grid[x][y]!=0)
            {
                curr = max(curr,dfs(grid,x,y,vis));
            }
        }
        vis[r][c] = 0;
        ans = max(ans,curr+grid[r][c]);
        return curr+grid[r][c];
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]==0) continue;
                vector<vector<int>> vis(m,vector<int>(n,0));
                dfs(grid,i,j,vis);
            }
        }
        return ans;
    }
};