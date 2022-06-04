class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> bought(n,vector<int>(3,0));
        vector<vector<int>> sold(n,vector<int>(3,0));
        bought[0][1] = -prices[0];
        bought[0][2] = -prices[0];
        
        for(int k=1; k<=2; k++)
        {
            for(int i=1; i<n; i++)
            {
                bought[i][k] = max(bought[i-1][k],sold[i][k-1]-prices[i]);
                sold[i][k] = max(sold[i-1][k],bought[i-1][k]+prices[i]);
            }
        }
        return sold[n-1][2];
    }
};