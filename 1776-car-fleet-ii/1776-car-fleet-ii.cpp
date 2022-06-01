class Solution {
public:

    vector<double> getCollisionTimes(vector<vector<int>>& A) {
        int n = A.size();
        vector<double> res(n,(double)-1);
        vector<int> stack;
        for(int i=n-1; i>=0; i--)
        {
            int p = A[i][0], s = A[i][1];
            while (!stack.empty()) {
                int j = stack.back(), p2 = A[j][0], s2 = A[j][1];
                if (s <= s2 || (1.0 * (p2 - p) / (s - s2) >= res[j] && res[j] > 0))
                    stack.pop_back();
                else
                    break;
            }
            if (!stack.empty())
                res[i] = 1.0 * (A[stack.back()][0] - p) / (s - A[stack.back()][1]);
            stack.push_back(i);
        }
        return res;
    }
};