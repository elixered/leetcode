class Solution {
public:
    
    int dist(vector<int>& v1, vector<int>& v2)
    {
        return (v1[0]-v2[0])*(v1[0]-v2[0]) + (v1[1]-v2[1])*(v1[1]-v2[1]);
    }
    
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size();
        int res = 0;
        map<pair<int,int>,int> hm;
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                int a = dist(points[i],points[j]);
                hm[{i,a}]++;
                hm[{j,a}]++;
            }
        }
        for(auto it:hm)
        {
            if(it.second>1)
            {
                int curr = it.second;
                curr = curr*(curr-1);
                res += curr;
            }
        }
        return res;
    }
};