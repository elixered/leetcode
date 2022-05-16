class Solution {
public:
    
    int solve(int x, int y, int x1, int y1)
    {
        
            return max(abs(y1-y),abs(x1-x));
    }
    
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;
        int n = points.size();
        int x = points[0][0];
        int y = points[0][1];
        if(n==1) return 0;
        for(int i=1; i<n; i++)
        {
            ans += solve(x,y,points[i][0],points[i][1]);
            x = points[i][0];
            y = points[i][1];
        }
        return ans;
    }
};