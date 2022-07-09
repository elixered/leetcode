class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        string rev(s);
        reverse(rev.begin(),rev.end());
        string s_new = s + "#" + rev;
        int n_new = s_new.size();
        vector<int> lps(n_new,0);
        for(int i=1; i<n_new; ++i){
            int j = lps[i-1];
            while(j && s_new[i] != s_new[j])
                j = lps[j-1];
            if(s_new[i] == s_new[j])
                j++;
            lps[i] = j;
        }
        return rev.substr(0,n-lps[n_new-1]) + s;
    }
};