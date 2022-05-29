class Solution {
public:
    struct node{
        int r,  c,  w;
        node(int x,int y,int z)
        {
            r = x;
            c = y;
            w = z;
        }
    };
    struct cmp{
        bool operator()(node a, node b)
        {
            return a.w>b.w;
        }
    };
    int minimumObstacles(vector<vector<int>>& grid) {
        priority_queue<node,vector<node>,cmp> pq;
        pq.push(node(0,0,0));
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
        dist[0][0]=0;
        vector<int> dr = {1,-1,0,0};
        vector<int> dc = {0,0,1,-1};
        while(!pq.empty())
        {
            int x = pq.top().r;
            int y = pq.top().c;
            int w = pq.top().w;
            if(x==m-1 && y==n-1) return w;
            pq.pop();
            if(w!=dist[x][y]) continue;
            for(int i=0; i<4; i++)
            {
                int nr = x+dr[i];
                int nc = y+dc[i];
                if(nr<m && nc<n && nr>=0 && nc>=0 && dist[nr][nc]>w+grid[nr][nc])
                {
                    dist[nr][nc] = w+grid[nr][nc];
                    pq.push({nr,nc,dist[nr][nc]});
                }
            }
        }
        return dist[m-1][n-1];
    }
};