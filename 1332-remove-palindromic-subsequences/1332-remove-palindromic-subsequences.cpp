class Solution {
public:
    bool p(string s)
    {
        string t = s;
        reverse(t.begin(),t.end());
        return t==s;
    }
    int removePalindromeSub(string s) {
        int n = s.size();
        if(p(s)) return 1;
        else return 2;
    }
};