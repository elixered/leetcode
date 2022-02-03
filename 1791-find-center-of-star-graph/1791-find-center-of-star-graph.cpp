class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int> map;
        int n = edges.size();
        for(auto& it:edges)
        {
            map[it[0]]++;
            map[it[1]]++;
        }
        int maxi = 0;
        int res = 0;
        for(auto& it:map)
        {
            if(it.second>maxi)
            {
                res = it.first;
                maxi = it.second;
            }
        }
        return res;
    }
};