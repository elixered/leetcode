class Solution {
public:
    int m,n;
    set<vector<int>> visited;
    bool valid(int x, int y){
        return x>=0 && y>=0 && x<m && y<n;
    }
    
    bool dfs(vector<vector<int>>& maze, vector<int>& start, vector<int>& dest){
        if(!valid(start[0],start[1])) return false;
        if(start == dest) return true;
        if(visited.find(start) != visited.end()) return false;
        visited.insert(start);
        vector<vector<int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
        for(int i=0; i<4; ++i){
            vector<int> end = getEnd(maze,start,dir[i]);
            if(end==dest or dfs(maze,end,dest)) return true;
        }
        return false;
    }
    
    vector<int> getEnd(vector<vector<int>>& maze, vector<int>& start, vector<int>& dir){
        int x = start[0], y = start[1];
        int dx = dir[0], dy = dir[1];
        while(valid(x,y) && maze[x][y]!=1){
            x += dx;
            y += dy;
        }
        return {x-dx,y-dy};
    }
    
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& dest) {
        m = maze.size();
        n = maze[0].size();
        return dfs(maze,start,dest);
    }
};