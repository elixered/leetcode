class Solution {
public:
    int numSub(string s) {
        int curr = s[0] == '1';
        int res = curr;
        int mod = 1e9 + 7;
        for(int i=1; i<s.size(); ++i){
            if(s[i]=='1')
                curr++;
            else curr = 0;
            res += curr;
            res %= mod;
        }
        return res;
    }
};