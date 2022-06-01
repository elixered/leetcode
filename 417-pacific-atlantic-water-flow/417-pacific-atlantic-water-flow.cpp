class Solution {
public:
    bool valid(int x, int y, int m, int n)
    {
        return x>=0 && y>=0 && x<m && y<n;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<int> dr = {1,-1,0,0};
        vector<int> dc = {0,0,1,-1};
        vector<vector<int>> vis(m,vector<int>(n,0));
        queue<pair<int,int>> q;
        for(int i=0; i<m; i++)
        {
            q.push({i,0});
            vis[i][0] = 1;
        }
        for(int j=1; j<n; j++)
        {
            q.push({0,j});
            vis[0][j] = 1;
        }
        
        while(!q.empty())
        {
            auto r = q.front().first;
            auto c = q.front().second;
            q.pop();
            for(int i=0; i<4; i++)
            {
                int x = r+dr[i];
                int y = c+dc[i];
                if(valid(x,y,m,n) && !vis[x][y] && heights[x][y]>=heights[r][c])
                {
                    vis[x][y] = 1;
                    q.push({x,y});
                }
            }
        }
        
        for(int i=0; i<m; i++)
        {
            q.push({i,n-1});
            vis[i][n-1] += 2;
        }
        for(int j=0; j<n-1; j++)
        {
            q.push({m-1,j});
            vis[m-1][j] += 2;
        }
        vector<vector<int>> ans;
        
         while(!q.empty())
        {
            auto r = q.front().first;
            auto c = q.front().second;
            q.pop();
            for(int i=0; i<4; i++)
            {
                int x = r+dr[i];
                int y = c+dc[i];
                if(valid(x,y,m,n) && vis[x][y]<2 && heights[x][y]>=heights[r][c])
                {
                    vis[x][y] += 2;
                    q.push({x,y});
                }
            }
        }
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(vis[i][j]==3)
                    ans.push_back({i,j});
            }
        }
        return ans;
    }
};