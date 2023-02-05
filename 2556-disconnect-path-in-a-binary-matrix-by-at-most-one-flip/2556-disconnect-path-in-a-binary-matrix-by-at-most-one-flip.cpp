class Solution {
public:
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        if((m == 1 && n == 1) || (m == 1 && n == 2) || (m == 2 && n == 1) )
            return false;
        
        queue<pair<int, int>> q;
        q.push({0,0});

        while(!q.empty())
        {
            int s = q.size();

            if(s == 1)
            {
                int x = q.front().first;
                int y = q.front().second;
                
                if( !((x == 0 && y == 0) || (x == m-1 && y == n-1) ) )
                    return true;
            }
            
            
            for(int  i = 0 ; i<s; i++)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
                if(x == m-1 && y == n-1)
                {
                    return false;
                }
                
                if(x+1<m && grid[x+1][y])
                {
 
                    if(x+1 != m-1 || y != n-1)
                    grid[x+1][y] = 0;

                    q.push({x+1,y});
                }
                
                if(y+1<n && grid[x][y+1])
                {

                    if(x != m-1 || y+1 != n-1)
                    grid[x][y+1] = 0;
                    
                    q.push({x,y+1});

                }
            }
        }
        
        return true;
    }
};