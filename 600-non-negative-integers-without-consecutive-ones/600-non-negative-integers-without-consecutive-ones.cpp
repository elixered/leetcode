class Solution {
public:
    int findIntegers(int n) {
        vector<int> dp(32,0);
        dp[0] = 1;
        dp[1] = 2;
        for(int i=2; i<32; ++i)
            dp[i] += dp[i-1] + dp[i-2];
        int k = 30;
        int ans = 0;
        int prev = 0;
        while(k>=0){
            if((n&(1<<k))){
                ans += dp[k];
                if(prev)
                    return ans;
                else prev = 1;
            }
            else
                prev = 0;
            k--;
        }
        return ans+1;
    }
};