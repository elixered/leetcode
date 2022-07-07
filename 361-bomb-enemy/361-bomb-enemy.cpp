class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> rowsum(m,vector<int>(n,0)),colsum(m,vector<int>(n,0));
        for(int i=0; i<m; ++i){
            rowsum[i][0] = grid[i][0] == 'E' ? 1:0;
            for(int j=1; j<n; ++j){
                if(grid[i][j]=='E')
                    rowsum[i][j] = rowsum[i][j-1]+1;
                else if(grid[i][j]=='W')
                    rowsum[i][j] = 0;
                else rowsum[i][j] = rowsum[i][j-1];
            }
            for(int j=n-2; j>=0; j--){
                if(grid[i][j]!='W')
                    rowsum[i][j] = max(rowsum[i][j],rowsum[i][j+1]);
            }
        }
        for(int j=0; j<n; ++j){
            colsum[0][j] = grid[0][j] == 'E' ? 1:0;
            for(int i=1; i<m; ++i){
                if(grid[i][j]=='E')
                    colsum[i][j] = colsum[i-1][j]+1;
                else if(grid[i][j]=='W')
                    colsum[i][j] = 0;
                else colsum[i][j] = colsum[i-1][j];
                if(grid[i-1][j] != 'W')
                    colsum[i-1][j] = max(colsum[i-1][j],colsum[i][j]);
            }
            for(int i=m-2; i>=0; i--){
                if(grid[i][j]!='W')
                    colsum[i][j] = max(colsum[i][j],colsum[i+1][j]);
            }
        }
        int mx = 0;
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(grid[i][j]=='0')
                    mx = max(mx,colsum[i][j]+rowsum[i][j]-(grid[i][j]=='E'));
            }
        }
        return mx;
    }
};