class Solution {
public:
    
    int mod = 1e9 + 7;
    vector<int> dir = {-1,0,1,0,-1};
    int dp[51][51][51];
    
    int solve(int m, int n, int moves, int sr, int sc){
        if(sr == m or sc == n or sr < 0 or sc < 0)
            return 1;
        if(moves == 0) return 0;
        if(dp[sr][sc][moves] != -1) return dp[sr][sc][moves];
        int ans = 0;
        for(int i=0; i<4; ++i){
            int x = sr + dir[i];
            int y = sc + dir[i+1];
            ans += solve(m,n,moves-1,x,y);
            ans %= mod;
        }
        return dp[sr][sc][moves] = ans;
    }
    
    int findPaths(int m, int n, int maxMove, int sr, int sc) {
        memset(dp,-1,sizeof(dp));
        return solve(m,n,maxMove,sr,sc);
    }
};