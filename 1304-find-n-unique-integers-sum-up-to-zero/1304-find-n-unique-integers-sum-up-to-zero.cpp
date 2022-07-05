class Solution {
public:
        vector<int> sumZero(int n) {
        vector<int> A(n);
        for (int i = 0; i < n; ++i)
            A[i] = i * 2 - n + 1;
        return A;
    }
};