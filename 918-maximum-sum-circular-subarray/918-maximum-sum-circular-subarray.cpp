class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
	    // add tow lines below can make it faster than 98.7%
	    ios::sync_with_stdio(false);
        cin.tie(0);
        vector<int> A2(A);
        for (auto a : A) A2.push_back(a);
        vector<long long> presum = {INT_MIN};
        for (auto a : A2) presum.push_back(presum[presum.size()-1] + a);
        long long res = A[0];
        deque<int> d;
        for (int i = 1; i < presum.size(); i++) {
            // delete invalid left index
            while (!d.empty() && i - d.front() > A.size()) d.pop_front();
            // check the answer before keeping deque increament
            if (!d.empty() && i != d.front()) res = max(res, presum[i] - presum[d.front()]);
            // keeping increament
            while (!d.empty() && presum[d.back()] > presum[i]) d.pop_back();
            // push into it
            d.push_back(i);
        }
        return res;
    }
};