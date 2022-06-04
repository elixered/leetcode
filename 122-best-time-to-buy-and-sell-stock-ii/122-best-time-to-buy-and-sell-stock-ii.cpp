class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> bought(n,0),sold(n,0);
        bought[0] = -prices[0];
        for(int i=1; i<n; i++)
        {
            bought[i] = max(bought[i-1],sold[i-1]-prices[i]);
            sold[i] = max(sold[i-1],bought[i-1]+prices[i]);
        }
        return sold[n-1];
    }
};