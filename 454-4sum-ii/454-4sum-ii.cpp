class Solution {
public:
   int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int res = 0;
        unordered_map<int, int> AB;
        for (int a : A)
            for (int b : B)
                AB[a + b]++;
        for (int c : C)
            for (int d : D)
                res += AB[-c - d];
        return res;
    }
};