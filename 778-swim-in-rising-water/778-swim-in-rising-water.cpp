class Solution {
public:
    vector<int> dir = {-1,0,1,0,-1};
    bool dfs(vector<vector<int>>& grid, int x, int y, int mid,vector<vector<int>>& visited){
        int n = grid.size();
        visited[x][y] = 1;
        for(int i=0; i<4; i++){
            int nx = x+dir[i];
            int ny = y+dir[i+1];
            if(nx>=0 && ny>=0 && nx<n && ny<n && !visited[nx][ny] && grid[nx][ny]<=mid){
                if(nx==n-1 && ny==n-1)
                    return true;
                if(dfs(grid,nx,ny,mid,visited))
                    return true;
            }
        }
        return false;
    }
    
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int low = 0;
        int high =n*n-1;
        int ans = n*n-1;
        while(low <= high){
            int mid = (low+high)/2;
            vector<vector<int>> visited(n, vector<int>(n, 0));
            if(grid[0][0]<=mid && dfs(grid,0,0,mid,visited)){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};