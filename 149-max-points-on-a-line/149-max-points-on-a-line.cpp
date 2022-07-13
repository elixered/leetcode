class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n<3) return n;
        int ans = 0;
        for(int i=0; i<n; ++i){
            map<pair<int,int>,set<int>> mp;
            for(int j=0; j<n; ++j){
                if(i==j) continue;
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                int dz = gcd(dx,dy);
                dx /= dz;
                dy /= dz;
                mp[{dx,dy}].insert(i);
                mp[{dx,dy}].insert(j);
                ans = max(ans,(int)mp[{dx,dy}].size());
            }
        }
        return ans;
    }
};