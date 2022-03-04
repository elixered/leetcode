class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(query_row+3);
        for(int i=1; i<=query_row+2; i++)
        {
            dp[i].resize(i,0);
        }
        int row = 1;
        dp[1][0] = poured;
        while(row<=query_row+1)
        {
            for(int i=0; i<dp[row].size(); i++)
            {
                if(dp[row][i]-(double)1 > 1e-9)
                {
                    double d = dp[row][i] - (double)1;
                    dp[row][i] = (double)1;
                    dp[row+1][i] += d/2;
                    dp[row+1][i+1] += d/2;
                }
            }
            row++;
        }
        return dp[query_row+1][query_glass];
    }
};