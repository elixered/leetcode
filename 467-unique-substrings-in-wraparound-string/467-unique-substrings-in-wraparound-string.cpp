class Solution {
public:
    int findSubstringInWraproundString(string p) {
        unordered_set<string> st;
        int i = 0;
        int n = p.size();
        vector<int> maxlen(n,1);
        for(int i=1; i<n; ++i){
            if(p[i]-'a' == (p[i-1]-'a'+1)%26)
                maxlen[i] += maxlen[i-1];
        }
        vector<int> count(26,0);
        for(int i=0; i<n; ++i)
            count[p[i]-'a'] = max(count[p[i]-'a'],maxlen[i]);
        int ans = 0;
        for(auto it:count)
            ans += it;
        return ans;
    }
};