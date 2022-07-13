class Solution {
public:
    int gcd(int x, int y) {
        if(y == 0) return x;
        return gcd(y, x % y);
    }
    
    int minimumLines(vector<vector<int>>& points) {
        if(points.size() < 3) return 1;
        vector<int> dp(1 << points.size(), INT_MAX);
        for(int i = 0; i < points.size(); i++) {
			dp[1 << i] = 1;
            for(int j = i + 1; j < points.size(); j++) {
                int key = (1 << i) | (1 << j);
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                int dz = gcd(dx, dy);
                dx /= dz;
                dy /= dz;
                
                for(int k = 0; k < points.size(); k++) {
                    if(k == i || k == j) continue;
                    int x = points[k][0] - points[i][0];
                    int y = points[k][1] - points[i][1];
                    int z = gcd(x, y);
                    x /= z;
                    y /= z;
                    if(x == dx && y == dy) key |= (1 << k);
                }
                dp[key] = 1;
                for(int k = ((key - 1) & key); k > 0; k = ((k - 1) & key)) {
                    dp[k] = 1;
                }
            }
        }
        
        for(int i = 3; i < dp.size(); i++) {
                for(int j = ((i - 1) & i); j > 0; j = ((j - 1) & i)) {
                    dp[i] = min(dp[i], dp[j] + dp[i - j]);
                }
        }
        return dp.back();
    }
};