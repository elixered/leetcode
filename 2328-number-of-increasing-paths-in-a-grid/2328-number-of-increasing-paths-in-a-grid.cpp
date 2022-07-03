class Solution {
public:
    int mod= pow(10,9)+7;
    vector<int> dir = {-1,0,1,0,-1};
    int dp[1002][1002];
    int dfs(vector<vector<int>>& grid, int i, int j){
        int m = grid.size();
        int n = grid[0].size();
        int res = 1;
        if(dp[i][j] != -1) return dp[i][j];
        for(int k=0; k<4; ++k){
            int x = i + dir[k];
            int y = j + dir[k+1];
            if(x>=0 && y>=0 && x<m && y<n && grid[x][y] > grid[i][j]){
                res += dfs(grid,x,y);
            }
        }
        return dp[i][j] = res%mod;
    }
    
    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        memset(dp,-1,sizeof(dp));
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                ans += dfs(grid,i,j);
                ans %= mod;
            }
        }
        return ans;
    }
};