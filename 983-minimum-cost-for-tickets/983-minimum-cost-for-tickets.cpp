class Solution {
public:
    int dp[400];
    int solve(vector<int>& days, int idx, vector<int>& costs){
        int n = days.size();
        if(idx == n) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int ans = solve(days,idx+1,costs)+min({costs[0],costs[1],costs[2]});
        for(int i=idx+1; i<n; ++i){
            if(days[i]-days[idx]+1<=7)
                ans = min(ans,solve(days,i+1,costs)+min(costs[1],costs[2]));
            else if(days[i]-days[idx]+1<=30)
                ans = min(ans,solve(days,i+1,costs)+costs[2]);
            else break;
        }
        return dp[idx] = ans;
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        sort(days.begin(),days.end());
        memset(dp,-1,sizeof(dp));
        return solve(days,0,costs);
    }
};