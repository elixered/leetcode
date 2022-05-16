class Solution {
public:
    
    int solve(int x, int y, int x1, int y1)
    {
        int signx,signy;
        if(x1>x) signx=1;
        else signx=-1;
        if(y1>y)
            signy=1;
        else signy = -1;

            int c = 0;
            while(y1!=y and x1!=x)
            {
                y+=signy;
                x+=signx;
                c++;
            }
        cout<<max(abs(y1-y),abs(x1-x));
            return c + max(abs(y1-y),abs(x1-x));
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