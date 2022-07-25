class Solution {
public:
    string breakPalindrome(string s) {
        int n = s.size();
        if(n==1) return "";
        int i = 0;        
        while(i < n && (s[i] == 'a' || (n%2 && i==n/2)))
            ++i;
        if(i == n)
            s[n-1] = 'b';
        else
            s[i] = 'a';
        return s;
    }
};