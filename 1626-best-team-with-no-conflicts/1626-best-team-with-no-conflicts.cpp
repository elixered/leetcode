class Solution {
public:
    
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>> p;
        int n = ages.size();
        vector<int> dp(n,0);
        for(int i=0; i<n; i++)
            p.push_back({ages[i],scores[i]});
        sort(begin(p),end(p));
        for(int i=0; i<n; i++)
            dp[i] = p[i].second;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(p[j].second>=p[i].second)
                {
                    dp[j] = max(dp[j],dp[i]+p[j].second);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};