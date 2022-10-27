class Solution {
public:
    int n;
    bool valid(int r, int c){
        return r>=0 && c>=0 && r<n && c<n;
    }
    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        vector<int> dir = {-1,0,1,0,-1};
        queue<pair<int,int>> q;
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                if(grid[i][j] == 1){
                    queue<pair<int,int>> t;
                    t.push({i,j});
                    grid[i][j] = 2;
                    while(!t.empty()){
                        auto [x,y] = t.front();
                        t.pop();
                        q.push({x,y});
                        for(int i=0; i<4; ++i){
                            auto r = x + dir[i];
                            auto c = y + dir[i+1];
                            if(!valid(r,c)) continue;
                            if(grid[r][c] == 1){
                                grid[r][c] = 2;
                                t.push({r,c});
                            }
                        }
                    }
                    break;
                }
                if(q.size()) break;
            }
            if(q.size()) break;
        }
        int steps = 0;
        while(!q.empty()){
            int k = q.size();
            while(k--){
                auto [x,y] = q.front();
                q.pop();
                for(int i=0; i<4; ++i){
                    auto r = x + dir[i];
                    auto c = y + dir[i+1];
                    if(!valid(r,c)) continue;
                    if(grid[r][c] == 1){
                        return steps;
                    }
                    else if(grid[r][c] == 0){
                        grid[r][c] = 2;
                        q.push({r,c});
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};