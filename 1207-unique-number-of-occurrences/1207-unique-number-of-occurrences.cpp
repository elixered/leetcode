class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> mp;
        for(auto i:arr)
            mp[i]++;
        unordered_map<int,int> counts;
        for(auto it:mp)
            counts[it.second]++;
        return mp.size()==counts.size();
    }
};