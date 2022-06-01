class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        int n = points.size();
        int ans = pow(10,9);
        unordered_map<int,unordered_set<int>> xmap;
        for(auto p:points)
            xmap[p[0]].insert(p[1]);
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                int x1 = points[i][0];  // A
                int y1 = points[i][1];  // A
                int x2 = points[j][0];  // B
                int y2 = points[j][1];  //B
                if(x1!=x2 && y1!=y2)
                {
                    if(xmap[x1].find(y2)!=xmap[x1].end() && xmap[x2].find(y1)!=xmap[x2].end())
                    {
                        int area = abs((y1-y2)*(x1-x2));
                        ans = min(area,ans);
                    }
                }
            }
        }
        return ans == pow(10,9) ? 0:ans;
    }
};