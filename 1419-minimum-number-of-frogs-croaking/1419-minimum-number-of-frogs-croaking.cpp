class Solution {
public:
    int minNumberOfFrogs(string s) {
        unordered_map<char,int> map;
        string cr = "croak";
        unordered_set<char> set(cr.begin(),cr.end());
        int ans = 0;
        for(auto it:s)
        {
            if(set.find(it)==set.end())
                return -1;
            map[it]++;
            ans = max(ans,map['c']-map['k']);
            if(map['c']>=map['r'] && map['r']>=map['o'] && map['o']>=map['a'] && map['a']>=map['k'])
                continue;
            else return -1;
        }
        int count = map['c'];
        for(auto it:map)
            if(it.second!=count)
                return -1;
        return ans;
    }
};