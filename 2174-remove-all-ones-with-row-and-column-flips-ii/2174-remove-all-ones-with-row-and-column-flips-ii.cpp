class Solution {
public:
    int m,n;
    const int MAX = 1000;
    
    bool allZero(vector<vector<int>> grid){
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++)
                if(grid[i][j]) return false;
        }
        return true;
    }
    
    int solve(vector<vector<int>> grid, int x, int y){
        if(y==n){
            x++;
            y = 0;
        }
        if(x==m){
            if(allZero(grid)) return 0;
            else return MAX;
        }
        int noChange = solve(grid,x,y+1);
        
        int change = MAX;
        if(grid[x][y]){
            for(int i=0; i<m; i++){
                for(int j=0; j<n; j++){
                    if(i==x or j==y)
                        grid[i][j] = 0;
                }
            }
            change = solve(grid,x,y+1)+1;
        }
        return min(change,noChange);
    }
    
    int removeOnes(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        return solve(grid,0,0);
    }
};