class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        sort(flowers.begin(),flowers.end());
        vector<pair<int,int>> p;
        int n = persons.size();
        for(int i=0; i<n; ++i){
            p.push_back({persons[i],i});
        }
        sort(begin(p),end(p));
        int f = 0;
        multiset<int> set;
        vector<int> ans(n,0);
        for(auto& [person,i] : p){
            for(; f<flowers.size() && person>=flowers[f][0]; ++f){
                set.insert(flowers[f][1]);
            }
            while(set.size() && *set.begin() < person){
                set.erase(set.begin());
            }
            ans[i] = set.size();
        }
        return ans;
    }
};