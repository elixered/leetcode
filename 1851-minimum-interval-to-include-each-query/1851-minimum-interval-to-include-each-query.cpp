class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n = queries.size();
        vector<int> ans(n,-1);
        vector<pair<int,int>> q;
        for(int i=0; i<n; i++)
            q.push_back({queries[i],i});
        sort(intervals.begin(), intervals.end());
        sort(q.begin(),q.end());
        set<pair<int,int>> set;
        int k = 0;
        for(auto& [query,i] : q){
            for(; k<intervals.size() && intervals[k][0]<=query; ++k){
                set.insert({intervals[k][1]-intervals[k][0]+1,intervals[k][1]});
            }
            while(set.size() && set.begin()->second<query)
                set.erase(set.begin());
            if(set.size())
                ans[i] = set.begin()->first;
        }
        return ans;
    }
};