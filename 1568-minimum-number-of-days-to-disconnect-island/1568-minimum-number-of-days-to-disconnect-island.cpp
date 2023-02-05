class Solution {
    int M, N, dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    void dfs(vector<vector<int>> &G, int i, int j,vector<vector<int>> &seen) {
        seen[i][j] = true;
        for (auto &[dx, dy] : dirs) {
            int x = dx + i, y = dy + j;
            if (x < 0 || x >= M || y < 0 || y >= N || G[x][y] != 1 || seen[x][y]) continue;
            dfs(G, x, y, seen);
        }
    }
    bool disconnected(vector<vector<int>> &G) {
        vector<vector<int>> seen(M, vector<int>(N, false));
        int cnt = 0;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (G[i][j] != 1 || seen[i][j]) continue;
                if (++cnt > 1) return true;
                dfs(G, i, j, seen);
            }
        }
        return cnt == 0;
    }
public:
    int minDays(vector<vector<int>>& G) {
        M = G.size(), N = G[0].size();
        if (disconnected(G)) return 0;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (G[i][j] != 1) continue;
                G[i][j] = 0;
                if (disconnected(G)) return 1;
                G[i][j] = 1;
            }
        }
        return 2;
    }
};