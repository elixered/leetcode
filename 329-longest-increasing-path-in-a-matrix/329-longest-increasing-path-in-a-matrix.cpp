class Solution {
public:
    vector<vector<int>> grid;
    int m,n;
    vector<int> dir = {-1,0,1,0,-1};
    bool valid(int x, int y)
    {
        return x>=0 && y>=0 && x<m && y<n;
    }
    int dfs(vector<vector<int>>& matrix, int x, int y, int d)
    {
        if(!valid(x,y)) return 0;
        if(grid[x][y]!=-1) return grid[x][y];
        int ans = 1;
        for(int i=0; i<4; i++)
        {
            int nx = x+dir[i];
            int ny = y+dir[i+1];
            if(valid(nx,ny) && matrix[nx][ny] > matrix[x][y])
                ans = max(ans,dfs(matrix,nx,ny,d+1)+1);
        }
        return grid[x][y] = ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        grid = vector<vector<int>>(m,vector<int>(n,-1));
        int ans = 0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]==-1)
                ans = max(ans,dfs(matrix,i,j,1));
            }
        }
        return ans;
    }
};