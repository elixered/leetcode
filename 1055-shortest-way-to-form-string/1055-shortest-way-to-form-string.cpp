class Solution {
public:
    
    unordered_map<char,vector<int>> mp;
    
    int move(string& source, string& target, int i){
        int j = 0;
        int n = source.size();
        int m = target.size();
        while(i<m && j<n){
            char curr = target[i];
            if(mp.find(curr) == mp.end()) return i;
            auto& v = mp[curr];
            auto idx = lower_bound(begin(v),end(v),j)-begin(v);
            if(idx == v.size()) return i;
            else{
                i++;
                j = v[idx]+1;
            }
        }
        return i;
    }
    
    int shortestWay(string source, string target) {
        int i = 0;
        int n = target.size();
        int s = 0;
        for(int j=0; j<source.size(); j++)
            mp[source[j]].push_back(j);
        while(i<n){
            int j = move(source,target,i);
            if(i==j) return -1;
            i = j;
            s++;
        }
        return s;
    }
};