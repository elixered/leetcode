class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size();
        int n = t.size();
        if(m>n) return false;
        unordered_map<char,vector<int>> map;
        for(int i=0; i<n; i++)
            map[t[i]].push_back(i);
        
        int prev = -1;
        for(auto c:s)
        {
            auto it = map.find(c);
            if(it==map.end()) return false;
            auto vec = it->second;
            int pos = upper_bound(vec.begin(),vec.end(),prev) - vec.begin();
            if(pos==vec.size()) return false;
            prev = vec[pos];
        }
        return true;
    }
};