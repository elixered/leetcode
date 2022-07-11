class Solution {
public:
    bool rotateString(string s, string goal) {
        int m = s.size();
        int n = goal.size();
        if(m != n) return false;
        string t = s + "#" + goal;
        int k = t.size();
        vector<int> lps(k,0);
        for(int i=1; i<k; ++i){
            int j = lps[i-1];
            while(j && t[i] != t[j])
                j = lps[j-1];
            if(t[i] == t[j])
                ++j;
            lps[i] = j;
        }
        int l = lps.back();
        if(l == 0) return s == goal;
        return s.substr(l) == goal.substr(0,n-l);
    }
};