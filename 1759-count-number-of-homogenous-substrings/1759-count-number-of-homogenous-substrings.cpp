class Solution {
public:
    int countHomogenous(string s) {
        int res = 1, mod = 1e9+7;
        int curr = 1;
        for(int i=1; i<s.size(); ++i){
            if(s[i] == s[i-1])
                curr++;
            else curr = 1;
            res += curr;
            res %= mod;
        }
        return res;
    }
};