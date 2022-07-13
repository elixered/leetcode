class Solution {
public:
int minimumLines(vector<vector<int>>& p) {
    int cnt = 0, dx = INT_MIN, dy = INT_MIN;
    sort(begin(p), end(p));
    for (int i = 1; i < p.size(); ++i) {
        int dx1 = p[i][0] - p[i - 1][0], dy1 = p[i][1] - p[i - 1][1], d = gcd(dx1, dy1);
        cnt += dx != dx1 / d || dy != dy1 / d;
        dx = dx1 / d;
        dy = dy1 / d;
    }
    return cnt;
} 
};