class Solution {
public:
    int maxProfit(int K, vector<int>& prices) {
        if(prices.size()<=1) return 0;
        int n = prices.size();
        vector<vector<int>> bought(n,vector<int>(K+1,0));
        vector<vector<int>> sold(n,vector<int>(K+1,0));
        for(int k=1;k<=K; k++)
            bought[0][k] = -prices[0];
        
        for(int k=1; k<=K; k++)
        {
            for(int i=1; i<n; i++)
            {
                bought[i][k] = max(bought[i-1][k],sold[i][k-1]-prices[i]);
                sold[i][k] = max(sold[i-1][k],bought[i-1][k]+prices[i]);
            }
        }
        return sold[n-1][K];
    }
};