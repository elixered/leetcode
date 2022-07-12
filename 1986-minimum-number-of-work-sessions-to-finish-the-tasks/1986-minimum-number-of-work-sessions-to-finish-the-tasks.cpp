class Solution {
public:
    int n, time, allOnes;
    int ans;
    int dp[1<<15][16];
    int minSessions(vector<int>& a, int t) {
        time = t;
        n = a.size();
        allOnes = (1<<n)-1;
        memset(dp, -1, sizeof dp);
        ans = help(a, 0, 0);
        return ans;
    }
    
    int help(vector<int> &a, int mask, int currTime){
        if(currTime > time) return INT_MAX;
        if(mask == allOnes) return 1;
        if(dp[mask][currTime] != -1) return dp[mask][currTime];
        int ans = INT_MAX;
        for(int i = 0 ; i < n ; i++){
            if( (mask & (1<<i)) == 0){
                int includeInCurrentSession = help(a, mask | (1<<i), currTime + a[i]);
                int includeInNextSession = 1 + help(a, mask | (1<<i), a[i]);
                ans = min({ans, includeInCurrentSession, includeInNextSession});
            }
        }
        return dp[mask][currTime] = ans;
    }
};