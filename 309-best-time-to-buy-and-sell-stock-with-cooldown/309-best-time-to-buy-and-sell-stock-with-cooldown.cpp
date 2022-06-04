class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n<=1) return 0;
        
        int bought,sold,rest;
        
        bought = -prices[0];
        sold = 0;
        rest = 0;
        
        for(int i=1; i<n; i++)
        {
            int prevBought = bought;
            bought = max(bought,rest-prices[i]);
            int prevSold = sold;
            sold = max(sold, prevBought+prices[i]);
            rest = prevSold;
        }
        return sold;
    }
};