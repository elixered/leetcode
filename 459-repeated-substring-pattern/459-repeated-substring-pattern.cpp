class Solution {
public:
    bool repeatedSubstringPattern(string s) {
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
        int k = n - lps[n-1];
        if(n%k != 0 or k==n)
            return false;
        string pat = s.substr(0,k);
        string ans;
        for(int i=0; i<n/k; ++i)
            ans += pat;
        return ans == s;
    }
};