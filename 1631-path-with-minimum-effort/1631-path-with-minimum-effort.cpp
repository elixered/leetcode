class Solution {
public:
    int minimumEffortPath(vector<vector<int>> &heights) {
        int left = 0;
        int right = 1000000;
        int result = right;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (canReachDestinaton(heights, mid)) {
                result = min(result, mid);
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return result;
    }

    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    // use bfs to check if we can reach destination with max absolute difference
    // k
    bool canReachDestinaton(vector<vector<int>> &heights, int mid) {
        int row = heights.size();
        int col = heights[0].size();
        queue<Cell> queue;
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        queue.push(Cell(0, 0));
        visited[0][0] = true;
        while (!queue.empty()) {
            Cell curr = queue.front();
            queue.pop();
            if (curr.x == row - 1 && curr.y == col - 1) {
                return true;
            }
            for (auto direction : directions) {
                int adjacentX = curr.x + direction[0];
                int adjacentY = curr.y + direction[1];
                if (isValidCell(adjacentX, adjacentY, row, col) &&
                    !visited[adjacentX][adjacentY]) {
                    int currentDifference = abs(heights[adjacentX][adjacentY] -
                                                heights[curr.x][curr.y]);
                    if (currentDifference <= mid) {
                        visited[adjacentX][adjacentY] = true;
                        queue.push(Cell(adjacentX, adjacentY));
                    }
                }
            }
        }
        return false;
    }

    bool isValidCell(int x, int y, int row, int col) {
        return x >= 0 && x <= row - 1 && y >= 0 && y <= col - 1;
    }

    class Cell {
    public:
        int x, y;
        Cell(int x, int y) {
            this->x = x;
            this->y = y;
        }
    };
};