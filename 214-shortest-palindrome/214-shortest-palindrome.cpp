class Solution {
public:
    #define ll long long
    string shortestPalindrome(string s) {
        int n = s.size();
        int p = 31, m = pow(10,9)+7;
        ll h1 = 0, h2 = 0;
        ll pow = 1;
        int ans = -1;
        for(int i=0; i<n; ++i){
            h1 = (h1*p + (s[i]-'a'+1))%m;
            h2 = (h2 + pow*(s[i]-'a'+1))%m;
            pow = (pow*p)%m;
            if(h1 == h2)
                ans = i;
        }
        string t = s;
        reverse(t.begin(),t.end());
        return t.substr(0,n-ans-1) + s;
    }
};