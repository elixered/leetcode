class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        bitset<5000> p(1);
        for (auto& r : mat) {
            bitset<5000> tmp;
            for (auto& i : r) {
                tmp = tmp | (p << i);
            }
            swap(p,tmp);
        }
        int res = 10000;
        for (int i = 0; i < 5000; ++i) {
            if (p[i]) res = min(res, abs(i - target));
        }
        return res;
    }
};