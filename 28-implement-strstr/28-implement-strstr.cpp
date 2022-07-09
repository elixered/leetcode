class Solution {
public:
    int strStr(string text, string pat) {
        int m = text.size();
        int n = pat.size();
        if(!n) return 0;
        vector<int> lps = processKMP(pat);
        for(int i=0,j=0; i<m; ){
            if(text[i] == pat[j]){
                i++;
                j++;
            }
            if(j==n)
                return i-j;
            if(i<m && text[i] != pat[j]){
                if(j)
                    j = lps[j-1];
                else i++;
            }
        }
        return -1;
    }
    
    vector<int> processKMP(string& s){
        int n = s.size();
        vector<int> lps(n,0);
        for(int i=1; i<n; ++i){
            int j = lps[i-1];
            while(j && s[i]!=s[j])
                j = lps[j-1];
            if(s[i] == s[j])
                j++;
            lps[i] = j;
        }
        return lps;
    }
    
};