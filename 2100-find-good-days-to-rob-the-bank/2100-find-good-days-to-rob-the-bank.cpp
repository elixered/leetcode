class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& A, int time) {
        int N = A.size(), left = 1;
        vector<int> right(N, 1), ans;
        for (int i = N - 2; i >= 0; --i) {
            if (A[i] <= A[i + 1]) right[i] += right[i + 1];
        }
        for (int i = 0; i + time < N; ++i) {
            if (i - 1 >= 0 && A[i] <= A[i - 1]) left++;
            else left = 1;
            if (left > time && right[i] > time) ans.push_back(i);
        }
        return ans;
    }
};