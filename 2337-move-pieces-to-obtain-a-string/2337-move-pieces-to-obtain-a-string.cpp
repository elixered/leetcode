class Solution {
public:
    bool canChange(string s, string t) {
        int n = s.size();
        int i = -1, j = -1;
        while(i < n && j < n){
            while(++i < n && s[i] == '_');
            while(++j < n && t[j] == '_');
            int quit = (i == n) + (j == n);
            if(quit) return quit == 2;
            if(s[i] != t[j] or (s[i] == 'L' ? i < j : i > j))
                return false;
        }
        return i==n && j==n;
    }
};