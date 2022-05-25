class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),
            [](const vector<int>& a, const vector<int>& b){
                if(a[0]==b[0]) return a[1] > b[1];
                else return a[0] < b[0];
            });
        int n = envelopes.size();
        vector<int> ans;
        for(int i=0; i<n; i++)
        {
            auto itr = lower_bound(ans.begin(),ans.end(),envelopes[i][1]);
            if(itr==ans.end())
                ans.push_back(envelopes[i][1]);
            else *itr = envelopes[i][1];
        }
        return ans.size();
    }
};