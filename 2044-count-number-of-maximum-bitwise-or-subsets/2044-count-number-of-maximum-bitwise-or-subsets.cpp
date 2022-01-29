class Solution {
public:
    int countMaxOrSubsets(vector<int>& A) {
        int goal = 0, N = A.size(), ans = 0;
        vector<int> dp(1 << N);
        for (int n : A) goal |= n;
        for (int m = 1; m < 1 << N; ++m) {
            int lowbit = m & -m;
            dp[m] = dp[m - lowbit] | A[__builtin_ctz(lowbit)];
            if (dp[m] == goal) ++ans;
        }
        return ans;
    }
};