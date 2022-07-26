class Solution {
public:
string removeDigit(string n, char digit) {
    for (int i = 0; i < n.size() - 1; ++i)
        if (n[i] == digit && n[i + 1] > digit)
            return n.substr(0, i) + n.substr(i + 1);
    int last_d = n.rfind(digit);
    return n.substr(0, last_d) + n.substr(last_d + 1);
}
};