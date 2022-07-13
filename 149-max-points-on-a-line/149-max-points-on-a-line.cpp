class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n<3) return n;
        int ans = 0;
        for(int i=0; i<n; ++i){
            for(int j=i+1; j<n; ++j){
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                int dz = gcd(dx,dy);
                int cnt = 2;
                for(int k=0; k<n; ++k){
                    if(i==k or j==k) continue;
                    int x = points[k][0] - points[i][0];
                    int y = points[k][1] - points[i][1];
                    int z = gcd(x,y);
                    if(dx/dz == x/z && dy/dz == y/z)
                        cnt++;
                }
                ans = max(ans,cnt);
            }
        }
        return ans;
    }
};