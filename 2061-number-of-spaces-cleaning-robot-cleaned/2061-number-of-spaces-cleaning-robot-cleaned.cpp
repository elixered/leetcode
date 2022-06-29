class Solution {
public:
    // UP RIGHT DOWN LEFT
    vector<vector<int>> directions = {{-1,0},{0,1},{1,0},{0,-1}};
    int cleaned[302][302];
    int vis[302][302][5];
    int m,n;
    int count = 0;
    
    bool valid(int x, int y){
        return x>=0 && y>=0 && x<m && y<n;
    }
    
    void dfs(vector<vector<int>>& room, int row, int col, int d){
        if(vis[row][col][d]) return;
        if(cleaned[row][col] == 0)
            ++count;
        cleaned[row][col] = 1;
        vis[row][col][d] = 1;
        int nr = row + directions[d][0];
        int nc = col + directions[d][1];
        if(!valid(nr,nc) or room[nr][nc]==1)
            return dfs(room,row,col,(d+1)%4);
        else dfs(room,nr,nc,d);
    }
    
    int numberOfCleanRooms(vector<vector<int>>& room) {
        m = room.size();
        n = room[0].size();
        memset(vis,0,sizeof(vis));
        memset(cleaned,0,sizeof(cleaned));
        dfs(room,0,0,1);
        return count;
    }
};