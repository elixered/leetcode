class Solution {
public:
    
    int dp[105][25][105];
    int solve(vector<int>& houses, vector<vector<int>>& cost, int n, int target, int idx, int prev){
        int h = houses.size();
        if(idx == h)
            return target == 0 ? 0 : 1e7;
        if(target < 0)
            return 1e7;
        if(dp[idx][prev+2][target+1] !=-1) return dp[idx][prev+2][target+1];
        int ans = 1e7;
        if(houses[idx] == 0){
            for(int j=1; j<=n; ++j){
                int res = solve(houses,cost,n,target-(prev!=j),idx+1,j) + cost[idx][j-1];
                ans = min(ans,res);
            }
        }
        else{
            int curr = houses[idx];
            ans = solve(houses,cost,n,target-(prev!=curr),idx+1,houses[idx]);
        }
        return dp[idx][prev+2][target+1] = ans;
    }
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp,-1,sizeof(dp));
        int ans = solve(houses,cost,n,target,0,-1);
        return ans >= 1e7 ? -1 : ans;
    }
};