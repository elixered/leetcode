class Solution {
public:
    
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<vector<int>> p;
        int n = ages.size();
        vector<int> dp(n,0);
        for(int i=0; i<n; i++)
            p.push_back({ages[i],scores[i]});
        sort(begin(p),end(p));
        for(int i=0; i<n; i++)
            dp[i] = p[i][1];
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(p[j][1]>=p[i][1])
                {
                    dp[j] = max(dp[j],dp[i]+p[j][1]);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};