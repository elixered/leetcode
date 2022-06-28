class Solution {
public:
    
    int m,n;
    bool valid(int x, int y){
        return x>=0 && y>=0 && x<m && y<n;
    }
    
    
    vector<int> getEnd(vector<vector<int>>& maze, vector<int> start, vector<int>& dir){
        int x = start[0], y = start[1];
        int dx = dir[0], dy = dir[1];
        int count = 0;
        while(valid(x,y) && maze[x][y]!=1){
            count++;
            x += dx;
            y += dy;
        }
        return {count-1,x-dx,y-dy};
    }
    
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& dest) {
        m = maze.size();
        n = maze[0].size();
        vector<vector<int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
        vector<vector<int>> dist(m,vector<int>(n,1e7));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> q;
        q.push({0,start[0],start[1]});
        while(!q.empty()){
            auto curr = q.top();
            q.pop();
            if(curr[1] == dest[0] && curr[2] == dest[1]) return curr[0];
            if(dist[curr[1]][curr[2]] < curr[0]) continue;
            for(int i=0; i<4; ++i){
                vector<int> end = getEnd(maze,{curr[1],curr[2]},dir[i]);
                if(dist[end[1]][end[2]] > curr[0]+end[0]){
                    dist[end[1]][end[2]] = curr[0]+end[0];
                    q.push({curr[0]+end[0],end[1],end[2]});
                }
            }
        }
        return -1;
    }
};