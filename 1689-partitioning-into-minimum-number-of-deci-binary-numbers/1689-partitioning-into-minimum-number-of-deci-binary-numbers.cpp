class Solution {
public:
    int minPartitions(string n) {
        auto ch = *max_element(begin(n),end(n));
        return ch-'0';
    }
};