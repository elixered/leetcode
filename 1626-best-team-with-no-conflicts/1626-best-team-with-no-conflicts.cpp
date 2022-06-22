class Solution {
public:
    vector<vector<int>> dp;
    int solve(int idx, int pIdx){
        if(idx == n) return 0;
        if(dp[idx][pIdx+1] != -1) return dp[idx][pIdx+1];
        int ans = 0;
        if(pIdx == -1 or p[pIdx][0]==p[idx][0] or p[idx][1]>=p[pIdx][1]){
            ans = max(solve(idx+1,pIdx),solve(idx+1,idx)+p[idx][1]);
        }
        else ans = solve(idx+1,pIdx);
        return dp[idx][pIdx+1] = ans;
    }
    
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        n = ages.size();
        dp = vector<vector<int>>(n+2,vector<int>(n+2,-1));
        for(int i=0; i<n; i++)
            p.push_back({ages[i],scores[i]});
        sort(begin(p),end(p));
        return solve(0,-1);
    }
private:
    int n;
    vector<vector<int>> p;
};