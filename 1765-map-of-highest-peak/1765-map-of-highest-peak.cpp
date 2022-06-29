class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& grid) {
        int m =grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans(m,vector<int>(n,-1));
        queue<pair<int,int>> q;
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(grid[i][j] == 1){
                    q.push({i,j});
                    ans[i][j] = 0;
                }
            }
        }
        int steps = 0;
        vector<int> dir = {-1,0,1,0,-1};
        while(!q.empty()){
            steps++;
            int t = q.size();
            while(t--){
                auto [x,y] = q.front();
                q.pop();
                for(int i=0; i<4; ++i){
                    int nx = x + dir[i];
                    int ny = y + dir[i+1];
                    if(nx>=0 && ny>=0 && nx<m && ny<n && ans[nx][ny] < 0){
                        ans[nx][ny] = steps;
                        q.push({nx,ny});
                    }
                }
            }
        }
        return ans;
    }
};