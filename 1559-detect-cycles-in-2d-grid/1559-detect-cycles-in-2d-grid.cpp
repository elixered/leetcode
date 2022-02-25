class Solution {
    public:
vector<int> d = {1, 0, -1, 0, 1};
bool containsCycle(vector<vector<char>>& g) {
    for (int i = 0; i < g.size(); ++i)
        for (int j = 0; j < g[i].size(); ++j) {
            if (g[i][j] >= 'a') {
                char val = g[i][j];
                vector<pair<int, int>> q = {{i, j}};
                while (!q.empty()) {
                    vector<pair<int, int>> q1;
                    for (auto [x, y] : q) {
                        if (g[x][y] < 'a')
                            return true;
                        g[x][y] -= 26;
                        for (auto k = 0; k < 4; ++k) {
                            int dx = x + d[k], dy = y + d[k + 1];
                            if (dx >= 0 && dy >= 0 && dx < g.size() && dy < g[dx].size() && g[dx][dy] == val)
                                q1.push_back({dx, dy});
                        }
                    }
                    swap(q, q1);
                }
            }
        }
    return false;
}
};