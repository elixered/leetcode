class Solution {
public:
    bool strongPasswordCheckerII(string p) {
    int lo = 0, up = 0, digit = 0, sz = p.size();
    for (int i = 0; i < sz; ++i) {
        if (i > 0 && p[i - 1] == p[i])
            return false;
        lo += islower(p[i]) ? 1 : 0;
        up += isupper(p[i]) ? 1 : 0;
        digit += isdigit(p[i]) ? 1 : 0;
    }
    return sz > 7 && lo && up && digit && (sz - lo - up - digit > 0);
}
};