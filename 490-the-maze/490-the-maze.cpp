class Solution {
public:
    int m,n;
    set<vector<int>> visited;
    bool valid(int x, int y){
        return x>=0 && y>=0 && x<m && y<n;
    }
    
    
    vector<int> getEnd(vector<vector<int>>& maze, vector<int> start, vector<int>& dir){
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
        vector<vector<int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
        queue<vector<int>> q;
        q.push(start);
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            if(curr == dest) return true;
            visited.insert(curr);
            for(int i=0; i<4; ++i){
                vector<int> end = getEnd(maze,curr,dir[i]);
                if(visited.find(end) == visited.end())
                    q.push(end);
            }
        }
        return false;
    }
};