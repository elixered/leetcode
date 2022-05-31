class Solution {
public:
   int waysToSplitArray(vector<int>& n) {
    long long right = accumulate(begin(n), end(n), 0LL), left = 0, res = 0;
    for (int i = 0; i < n.size() - 1; ++i) {
        left += n[i];
        right -= n[i];
        res += left >= right;
    }
    return res;
}
};