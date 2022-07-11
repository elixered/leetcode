class Solution {
public:
    long long numberOfSubstrings(string s) {
        unordered_map<char, long long> map;
        for (const char ch: s) {
            map[ch]++;
        }
        long long result = 0;
        for (const auto& p: map) {
            result += p.second*(p.second-1)/2;
        }
        result += s.length();
        return result;
    }
};