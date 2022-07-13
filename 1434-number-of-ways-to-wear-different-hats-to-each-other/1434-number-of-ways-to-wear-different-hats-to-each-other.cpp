class Solution {
public:
    int numberWays(vector<vector<int>>& hats) {
        int n = hats.size();
        vector<vector<int>> persons(40);
        for(int i=0; i<n; ++i)
            for(auto h:hats[i])
                persons[h-1].emplace_back(i);
        int allPersons = (1<<n);
        vector<int> dp(allPersons);
        dp[0] = 1;
        int mod = 1e9+7;
        for(int i=0; i<40; ++i){
            for(int mask=allPersons-1; mask>=0; --mask){
                for(auto p:persons[i]){
                    if((mask&(1<<p)) == 0){
                        dp[mask|(1<<p)] += dp[mask];
                        dp[mask|(1<<p)] %= mod;
                    }
                }
            }
        }
        return dp[allPersons-1];
    }
};