class Solution {
    public:
 vector<int> dir = { 0, 1, 0, -1, 0 }; 
    bool isCyclic(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j, int x, int y)
    {
        visited[i][j] = true;
        for(int d = 0; d < 4; ++d)
        {
            int a = i+dir[d];
            int b = j+dir[d+1];
            if(a >= 0 && a < grid.size() && b >= 0 && b < grid[0].size() && grid[a][b] == grid[i][j] && !(x == a && y == b))
                if(visited[a][b] || isCyclic(grid, visited, a,b,i,j))
                    return true;
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                if(!visited[i][j] && isCyclic(grid, visited, i, j, -1, -1))
                    return true;
        return false;
    }
};