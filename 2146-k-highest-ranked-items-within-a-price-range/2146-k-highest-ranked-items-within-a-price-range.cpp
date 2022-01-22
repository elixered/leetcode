class Solution {
public:

    class node{
        public:
        int dist;
        int price;
        int row;
        int col;
        node(int a, int b, int c,int d)
        {
            dist=a;
            price=b;
            row=c;
            col=d;
        }
    };
    struct cmp{
        bool operator()(node& a, node& b)
        {
            if(a.dist<b.dist) return true;
            else if(a.dist>b.dist) return false;
            else if(a.price<b.price) return true;
            else if(a.price>b.price) return false;
            else if(a.row<b.row) return true;
            else if(a.row>b.row) return false;
            else if(a.col<b.col) return true;
            else return false;
        }
    };
    priority_queue<node,vector<node>,cmp> pq;
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        vector<vector<int>> ans;
        vector<int> dirx = {0,0,-1,1};
        vector<int> diry = {-1,1,0,0};
        if(grid[start[0]][start[1]]==0)
            return ans;
        int d = 0;
        queue<vector<int>> q;
        q.push(start);
        if(grid[start[0]][start[1]]>1 && grid[start[0]][start[1]]>=pricing[0] &&  grid[start[0]][start[1]]<=pricing[1])
            pq.push(node(d,grid[start[0]][start[1]],start[0],start[1]));
         grid[start[0]][start[1]] = -1;
        int m = grid.size();
        int n = grid[0].size();
        while(!q.empty())
        {
            d++;
            int z = q.size();
            while(z--)
            {
            auto it = q.front();
            q.pop();
            for(int i=0; i<4; i++)
            {
                int x = it[0]+dirx[i];
                int y = it[1]+diry[i];
                if(x<0 or y<0 or x>=m or y>=n or grid[x][y]<=0) continue;
                q.push({x,y});
                if(grid[x][y]>=pricing[0] && grid[x][y]<=pricing[1] && grid[x][y]!=1)
                pq.push(node(d,grid[x][y],x,y));
                if(pq.size()>k) pq.pop();
                grid[x][y] = -1;
            }
            }
        }
        while(!pq.empty())
        {
            auto it = pq.top();
            ans.push_back({it.row,it.col});
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};