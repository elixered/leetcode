class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string t) {
        vector<string> ans;
        int n = t.size();
        unordered_map<char,char> mp1,mp2;
        for(auto& s:words){
            int m = s.size();
            if(m != n)
                continue;
            mp1.clear();
            mp2.clear();
            bool flag = true;
            for(int i=0; i<n; ++i){
                if(mp1.count(s[i]) && mp1[s[i]] != t[i] or mp2.count(t[i]) && mp2[t[i]] != s[i]){
                    flag = false;
                    break;
                }
                else{
                    mp1[s[i]] = t[i];
                    mp2[t[i]] = s[i];
                }
            }
            if(flag)
                ans.push_back(s);
        }
        return ans;
    }
};