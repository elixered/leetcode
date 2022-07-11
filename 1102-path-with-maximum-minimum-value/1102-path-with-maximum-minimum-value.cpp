class Solution {
    // uf for recording all the roots.
    vector<int> uf;
    vector<int> rank;

    // Find the root of x.
    int find(int x) {
        if (x != uf[x]) {
            uf[x] = find(uf[x]);
        }
        return uf[x];
    }  

    // union the roots of x and y.
    void uni(int x, int y) {
        int rootX = find(x), rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                uf[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                uf[rootX] = rootY;
            } else {
                uf[rootY] = rootX;
                rank[rootX] += 1;
            }
        }
    }

public:    
    int maximumMinimumPath(vector<vector<int>>& grid) {
        int R = grid.size(), C = grid[0].size();

        // Sort all the cells by their values.
        vector<vector<int>> vals;

        // 4 directions to a cell's possible neighbors.
        vector<vector<int>> dirs{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        
        // Intialize the rank of all the cells.
        rank = vector<int>(R * C, 1);

        // Root of all the R * C cells
        uf = vector<int>(R * C, 0);
        
        // Initalize the status of all the cells as false (unvisited).
        vector<vector<bool>> visited(R, vector<bool>(C));

        // Intialize the root of all the cells.
        for (int row = 0; row < R; ++row) {
            for (int col = 0; col < C; ++col) {
                uf[row * C + col] = row * C + col;
                vals.push_back({grid[row][col], row, col});
            }
        }

        // Sort all the cells by values from the largest to the smallest.
        sort(vals.begin(), vals.end(), greater<vector<int>>());
        
        // Iteration over the sorted cells.
        for (vector<int>& curGrid : vals) {
            int curRow = curGrid[1], curCol = curGrid[2];
            int curPos = curRow * C + curCol;

            // Mark the current cell as visited.
            visited[curRow][curCol] = true;
            for (vector<int> dir : dirs) {
                int newRow = curRow + dir[0], newCol = curCol + dir[1];
                int newPos = newRow * C + newCol;

                // Check if the current cell has any unvisited neighbors 
                // with value larger than or equal to val.
                if (newRow >= 0 && newRow < R && newCol >= 0 && newCol < C 
                    && visited[newRow][newCol]) {
                    // If so, we connect the current cell with this neighbor.
                    uni(curPos, newPos);
                }
            }

            // Check if the top-left cell is connected with the bottom-right cell.
            if (find(0) == find(R * C - 1)) { 
                // If so, return the value of the current cell.
                return grid[curRow][curCol];
            }
        }
        return 0;
    }
};
