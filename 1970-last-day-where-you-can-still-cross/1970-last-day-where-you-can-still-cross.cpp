class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int left = 1, right = cells.size(), ans = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canWalk(cells, row, col, mid)) {
                ans = mid; // Update current answer so far
                left = mid + 1; // Try to find a larger day
            } else right = mid - 1; // Try to find a smaller day
        }
        return ans;
    }
    int DIR[5] = {0, 1, 0, -1, 0};
    bool canWalk(vector<vector<int>>& cells, int row, int col, int dayAt) {
        vector<vector<bool>> grid(row, vector<bool>(col, 0)); // Create grid in the `dayAt` th date
        for (int i = 0; i < dayAt; ++i) grid[cells[i][0]-1][cells[i][1]-1] = 1;
        queue<pair<int, int>> bfs;
        for (int c = 0; c < col; ++c) {
            if (grid[0][c] == 0) { // Add all valid start cells in the top row
                bfs.push({0, c});
                grid[0][c] = 1; // Mark as visited
            }
        }
        while (!bfs.empty()) {
            auto [r, c] = bfs.front(); bfs.pop();
            if (r == row - 1) return true; // Reach to bottom -> Return Valid
            for (int i = 0; i < 4; ++i) {
                int nr = r + DIR[i], nc = c + DIR[i+1];
                if (nr < 0 || nr == row || nc < 0 || nc == col || grid[nr][nc] == 1) continue;
                grid[nr][nc] = 1; // Mark as visited
                bfs.push({nr, nc});
            }
        }
        return false;
    }
};