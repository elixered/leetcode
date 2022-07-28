class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        for(auto s:words)
            mp[s]++;
        vector<pair<int,string>> v;
        for(auto it:mp)
            v.push_back({it.second,it.first});
        auto cmp = [](pair<int,string> p1, pair<int,string> p2){
            if(p1.first == p2.first)
                return p1.second < p2.second;
            else return p1.first > p2.first;
        };
        sort(begin(v),end(v),cmp);
        vector<string> ans;
        int n = v.size();
        for(int i=0; i<k; ++i){
            ans.push_back(v[i].second);
        }
        return ans;
    }
};