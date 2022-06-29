class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(begin(items),end(items));
        vector<vector<int>> qs(queries.size());
        for(int i=0; i<queries.size(); ++i)
            qs[i] = {queries[i],i};
        sort(begin(qs),end(qs));
        int i = 0;
        int maximum = 0;
        vector<int> ans(queries.size());
        for(int j=0; j<queries.size(); ++j){
            while(i < items.size() && items[i][0] <= qs[j][0]){
                maximum = max(maximum,items[i][1]);
                ++i;
            }
            ans[qs[j][1]] = maximum;
        }
        return ans;
    }
};