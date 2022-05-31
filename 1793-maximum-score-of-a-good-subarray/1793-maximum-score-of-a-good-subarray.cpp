class Solution {
public:
    int maximumScore(vector<int>& A, int k) {
        int i = k - 1, j = k + 1, N = A.size(), ans = A[k], mn = A[k]; 
        for (int len = 2; len <= N; ++len) {
            int lmin = min(mn, i >= 0 ? A[i] : 0);
            int rmin = min(mn, j < N ? A[j] : 0); 
            if (lmin >= rmin) --i; 
            else ++j;
            mn = max(lmin, rmin);
            ans = max(ans, mn * len);
        }
        return ans;
    }
};