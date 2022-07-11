class Solution {
public:
    int maximumMinimumPath(vector<vector<int>>& grid) {
        int R = grid.size(), C = grid[0].size();

        // 4 directions to a cell's possible neighbors.
        vector<vector<int>> dirs{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        // Put the top-left cell to the priority queue and mark it as true (visited).
        priority_queue<pair<int, pair<int, int>>> pq;
        pq.push({grid[0][0], {0, 0}});

        // Initalize the status of all the cells as false (unvisited).
        vector<vector<bool>> visited(R, vector<bool>(C));

        // Mark the top-left cell as visited.
        visited[0][0] = true;
        int ans = grid[0][0];
        
        // While the priority queue is not empty.
        while (!pq.empty()) {
            // Pop the cell with the largest value.
            int curRow = pq.top().second.first;
            int curCol = pq.top().second.second;
            int curVal = pq.top().first;
            pq.pop();

            // Update the minimum value we have visited so far.
            ans = min(ans, curVal);
            
            // If we reach the bottom-right cell, stop the iteration.
            if (curRow == R - 1 && curCol == C - 1) {
                break;
            }
            
            for (vector<int> dir : dirs) {
                int newRow = curRow + dir[0];
                int newCol = curCol + dir[1];

                // Check if the current cell has any unvisited neighbors.
                if (newRow >= 0 && newRow < R && newCol >= 0 
                    && newCol < C && !visited[newRow][newCol]) {
                    // If so, we put this neighbor to the priority queue 
                    // and mark it as true (visited).
                    pq.push({grid[newRow][newCol], {newRow, newCol}});
                    visited[newRow][newCol] = true;
                }
            }
        }
        
        // Return the minimum value we have seen, which is the value of this path.
        return ans;
  }
};
