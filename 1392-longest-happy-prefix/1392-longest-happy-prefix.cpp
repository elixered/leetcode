class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        vector<int> lps(n,0);
        for(int i=1; i<n; ++i){
            int j = lps[i-1];
            while(j && s[i] != s[j])
                j = lps[j-1];
            if(s[i] == s[j])
                j++;
            lps[i] = j;
        }
        if(lps.back()==0) return "";
        return s.substr(0,lps.back());
    }
};