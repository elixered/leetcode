class Solution {
public:
    int dp[1002][1002];
    #define maxi pow(10,7)
    int dfs(vector<vector<int>>& books, int idx, int curr, int width)
    {
        int n = books.size();
        if(curr>width)
            return maxi;
        if(idx==n) return 0;
        if(dp[idx][curr]!=-1) return dp[idx][curr];
        int ans = maxi;
        int mx = 0;
        int sum = 0;
        for(int i=idx; i<n; i++)
        {
            mx = max(mx,books[i][1]);
            sum += books[i][0];
            ans = min(ans,mx+dfs(books,i+1,sum+curr,width));
            if(sum+curr<=width)
                ans = min(ans,mx+dfs(books,i+1,0,width));
        }
        return dp[idx][curr] = ans;
    }
    
    int minHeightShelves(vector<vector<int>>& books, int width) {
        memset(dp,-1,sizeof(dp));
        return dfs(books,0,0,width);
    }
};