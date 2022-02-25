class Solution {
private:
    int m,n;
    vector<vector<int>> vis;
    
    bool hasCycle(vector<vector<char>>& grid, int r, int c,char ch, vector<int> prev)
    {
        if(r<0 or c<0 or r>=m or c>=n or grid[r][c]!=ch)
            return false;
        if(vis[r][c])
            return true;
        vis[r][c] = 1;
        if(prev[0]!=r+1 or prev[1]!=c)
            if(hasCycle(grid,r+1,c,ch,{r,c}))
                return true;
        if(prev[0]!=r-1 or prev[1]!=c)
            if(hasCycle(grid,r-1,c,ch,{r,c}))
                return true;
        if(prev[0]!=r or prev[1]!=c+1)
            if(hasCycle(grid,r,c+1,ch,{r,c}))
                return true;
        if(prev[0]!=r or prev[1]!=c-1)
            if(hasCycle(grid,r,c-1,ch,{r,c}))
                return true;
        return false;
    }
    
public:
    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vis = vector<vector<int>>(m,vector<int>(n,0));
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(!vis[i][j] && hasCycle(grid,i,j,grid[i][j],{-1,-1}))
                    return true;
            }
        }
        return false;
    }
};