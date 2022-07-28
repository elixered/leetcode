class Solution {
public:
int dfs(vector<vector<int>> &g, int i, int j) {
    if (min(i, j) < 0 || max(i, j) >= g.size() || g[i][j] != 0)
        return 0;
    g[i][j] = 1;
    return 1 + dfs(g, i - 1, j) + dfs(g, i + 1, j) + dfs(g, i, j - 1) + dfs(g, i, j + 1);
}
int regionsBySlashes(vector<string>& grid) {
    int n = grid.size(), regions = 0;
    vector<vector<int>> g(n * 3, vector<int>(n * 3, 0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (grid[i][j] == '/') 
                g[i * 3][j * 3 + 2] = g[i * 3 + 1][j * 3 + 1] = g[i * 3 + 2][j * 3] = 1;
            else if (grid[i][j] == '\\') 
                g[i * 3][j * 3] = g[i * 3 + 1][j * 3 + 1] = g[i * 3 + 2][j * 3 + 2] = 1;
    for (int i = 0; i < n * 3; ++i)
        for (int j = 0; j < n * 3; ++j)
            regions += dfs(g, i, j) ? 1 : 0;    
    return regions;
}
};