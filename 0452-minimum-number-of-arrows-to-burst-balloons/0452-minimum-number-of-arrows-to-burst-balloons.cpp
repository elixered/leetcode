class Solution {
public:
    static bool cmp(vector<int>& v1, vector<int>& v2)
    {
        return v1[1]<v2[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(),points.end(),cmp);
        int arrows = 1;
        int end = points[0][1];
        for(int i=1; i<n; i++)
        {
            int currstart = points[i][0];
            if(currstart<=end)
                continue;
            else
            {
                arrows++;
                end = points[i][1];
            }
        }
        return arrows;
    }
};