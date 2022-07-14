class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& e) {
        queue<pair<int,int>> q;
        q.push({e[0],e[1]});
		
        int moves=1;
        int rows=maze.size();
        int cols=maze[0].size();
        
        vector<vector<int>> offsets={{0,1},{1,0},{0,-1},{-1,0}};
		
        maze[e[0]][e[1]]='+';
        while(!q.empty())
        {
            int l=q.size();
            for(int k=0;k<l;k++)
            {
                auto [i,j]=q.front();
                q.pop();
                
                for(int l=0;l<4;l++)
                {
                    int x=i+offsets[l][0];
                    int y=j+offsets[l][1];
                    if(x<0 || y<0 || x>=rows || y>=cols || maze[x][y]=='+')
                        continue;
                    if(x==0 || y==0 || x==rows-1 || y==cols-1)
                        return moves;
                    maze[x][y]='+';
                    q.push({x,y});
                }
            }
            moves++;
            
        }
        return -1;
    }
};