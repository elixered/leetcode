class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> mp;
        for(int i=0; i<order.size(); i++)
            mp[order[i]] = i;
        auto cmp = [&mp](char a, char b){
            return mp[a] < mp[b];
        };
        sort(s.begin(),s.end(),cmp);
        return s;
    }
};