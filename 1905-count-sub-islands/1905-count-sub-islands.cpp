class Solution {
public:
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int x, int y, int &res) {
        int m = grid1.size(), n = grid1[0].size();
        if(x < 0 || y < 0 || x >= m || y >= n) return;
        if(grid1[x][y] == 0 && grid2[x][y] == 1) {
            res = false;
        }
        if(grid2[x][y] == 0) return;
        grid2[x][y] = 0;
        dfs(grid1, grid2, x + 1, y, res);
        dfs(grid1, grid2, x, y + 1, res);
        dfs(grid1, grid2, x - 1, y, res);
        dfs(grid1, grid2, x, y - 1, res);
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size(), n = grid1[0].size();
        int ans = 0;
        for(int i = 0; i < m ; i++) {
            for(int j = 0; j < n; j++) {
                if(grid2[i][j] == 1) {
                    int res = true;
                    dfs(grid1, grid2, i, j, res);
                    ans += res;
                }
            }
        }
        return ans;
    }
};