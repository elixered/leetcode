class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int,int>> q;
        if(grid[0][0]==1) return -1;
        int ans = -1;
        q.push({0,0});
        int mx = n*n;
        pair<int,int> end = {n-1,n-1};
        int count = 1;
        while(!q.empty() and mx--)
        {
            int m = q.size();
            while(m--)
            {
                auto f = q.front();
                if(f==end)
                    return count;
                q.pop();
                for(int i=-1; i<=1; i++)
                {
                    for(int j=-1; j<=1; j++)
                    {
                        if(i==0 && j==0) continue;
                        int x = f.first+i;
                        int y = f.second+j;
                        if(x>=0 && y>=0 && x<n && y<n && grid[x][y]==0)
                        {
                            q.push({x,y});
                            grid[x][y] = 1;
                        }
                    }
                }
            }
            count++;
        }
        return -1;
    }
};