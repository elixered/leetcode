class Solution {
public:
   int countSubstrings(string &s, string &t) {
    int res = 0;
    int dpl[101][101] = {}, dpr[101][101] = {};
    for (int i = 1; i <= s.size(); ++i)
        for (int j = 1; j <= t.size(); ++j)
            if (s[i - 1] == t[j - 1])
                dpl[i][j] = 1 + dpl[i - 1][j - 1];
    for (int i = s.size(); i > 0; --i)
        for (int j = t.size(); j > 0; --j)
            if (s[i - 1] == t[j - 1])
                dpr[i - 1][j - 1] = 1 + dpr[i][j];
    for (int i = 0; i < s.size(); ++i)
        for (int j = 0; j < t.size(); ++j)
            if (s[i] != t[j])
                res += (dpl[i][j] + 1) * (dpr[i + 1][j + 1] + 1);
    return res;
}
};