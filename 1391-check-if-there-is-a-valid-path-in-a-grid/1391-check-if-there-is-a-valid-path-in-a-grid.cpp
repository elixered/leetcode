class Solution {
public:
    bool is_valid(int x,int y,vector<vector<int> > &grid)
    {
        if(x<0 || y<0 || x>=grid.size() || y>=grid[0].size())
            return 0;
        return 1;
    }
    void dfs(int x,int y,vector<vector<bool> > &visited,vector<vector<int> > &grid){
        if(visited[x][y])
            return;
        visited[x][y] = 1;
        int up,down,left,right;
        up=down=left=right=0;
        if(grid[x][y] == 1)
            left=right=1;
        else if(grid[x][y] == 2)
            up=down=1;
        else if(grid[x][y] == 3)
            left=down=1;
        else if(grid[x][y] == 4)
            down=right=1;
        else if(grid[x][y] == 5)
            up = left = 1;
        else
            right=up=1;
        if(up)
        {
            int new_x=x-1,new_y=y;
            if(is_valid(new_x,new_y,grid) && (grid[new_x][new_y]==2 || grid[new_x][new_y]==3 || grid[new_x][new_y]==4))
               dfs(new_x,new_y,visited,grid);
        }
        if(down)
        {
            int new_x=x+1,new_y=y;
            if(is_valid(new_x,new_y,grid) && (grid[new_x][new_y]==2 || grid[new_x][new_y]==5 || grid[new_x][new_y]==6))
               dfs(new_x,new_y,visited,grid);
        }
        if(left)
       {
            int new_x=x,new_y=y-1;
            if(is_valid(new_x,new_y,grid) && (grid[new_x][new_y]==1 || grid[new_x][new_y]==4 || grid[new_x][new_y]==6))
               dfs(new_x,new_y,visited,grid);
       }
        if(right)
       {
            int new_x=x,new_y=y+1;
            if(is_valid(new_x,new_y,grid) && (grid[new_x][new_y]==1 || grid[new_x][new_y]==3 || grid[new_x][new_y]==5))
                dfs(new_x,new_y,visited,grid);
       }
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size();
        if(!n)
            return 1;
        int m = grid[0].size();
        vector <vector<bool> > visited(n,vector<bool>(m,0));
        dfs(0,0,visited,grid);
        return visited[n-1][m-1];
    }
};