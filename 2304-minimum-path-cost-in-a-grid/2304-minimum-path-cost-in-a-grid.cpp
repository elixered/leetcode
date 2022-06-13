class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
    int m = grid.size(), n = grid[0].size();
    vector<int> prev = grid[0];

    for(int i=1; i<m; i++){
        vector<int> cur(n, INT_MAX);
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                int cost = prev[j] + grid[i][k] + moveCost[grid[i-1][j]][k];
                cur[k] = min(cur[k], cost);
            }
        }
        prev = cur;
    }

    return *min_element(prev.begin(), prev.end());
}
};