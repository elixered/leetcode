class Solution {
public:
    
    int solve(string a, string b, int l){
        string curr = b.substr(0,l);
        int idx = l;
        int count = 1;
        while(idx < b.size()){
            int j = 0;
            while(idx < b.size() && j < a.size()){
                curr += a[j++];
                idx++;
            }
            count++;
        }
        return curr == b ? count: INT_MAX;
    }
    
    int repeatedStringMatch(string a, string b) {
        string s = b+"#"+a;
        int n = s.size();
        vector<int> lps(n,0);
        for(int i=1; i<n; ++i){
            int j = lps[i-1];
            while(j && s[i] != s[j])
                j = lps[j-1];
            if(s[i] == s[j])
                j++;
            lps[i] = j;
            if(lps[i] >= b.size()) return 1;
        }
        int l = lps[n-1];
        int count = INT_MAX;
        for(int i=l; i>=1; i--){
            count = solve(a,b,i);
            if(count != INT_MAX)
                return count;
        }
        return -1;
    }
};