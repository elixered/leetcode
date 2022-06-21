class Solution {
public:
    bool removeOnes(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i=0; i<n; i++){
            if(grid[0][i] == 1){
                for(int j=0; j<m; j++){
                    grid[j][i] = !grid[j][i];
                }
            }
        }
        
        for(int i=1; i<m; i++){
            int ones = 0;
            for(int j=0; j<n; j++)
                ones += grid[i][j];
            if(ones!=0 && ones!=n)
                return false;
        }
        
        return true;
    }
};