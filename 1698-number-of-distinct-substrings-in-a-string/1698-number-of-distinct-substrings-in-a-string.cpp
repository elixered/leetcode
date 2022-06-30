class Solution {
public:
    int countDistinct(string s) {
    long res = 1, s_hash = 0, base = 1, mod = 1000000009;
    for (auto i = 0; i + 1 < s.size(); ++i) {
        s_hash = (s_hash * 26 + s[i]) % mod;
        base = base * 26 % mod; 
        unordered_set<int> us{(int)s_hash};
        for (long j = i + 1, hash = s_hash; j < s.size(); ++j) {
            hash = (mod + hash * 26 + s[j] - base * s[j - i - 1] % mod) % mod;
            us.insert((int)hash);
        }
        res += us.size();
    }
    return res;
}
};