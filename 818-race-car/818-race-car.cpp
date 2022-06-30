class Solution {
public:
    int racecar(int target) {
        vector<int> dp(target+1, INT_MAX);
        int r = 1;
        for (int i = 1; i <= target; i++) {
            if (i == pow(2,r)-1) {
                dp[i] = r;
                r++;
            }
            else {
                for (int j = 0; j < r-1; j++) {
                    dp[i] = min(dp[i],r+j+1+dp[i-pow(2,r-1)+pow(2,j)]);
                }
                dp[i] = min(dp[i], r+1+dp[pow(2,r)-1-i]);
            }
        }
        return dp[target];
    }
};