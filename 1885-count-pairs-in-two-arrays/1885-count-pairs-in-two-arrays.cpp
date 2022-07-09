class Solution {
public:
    long long countPairs(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> diff(n);
        for (int i = 0; i < n; i++) { 
            diff[i] = nums1[i] - nums2[i];
        }
        sort(diff.begin(), diff.end());
        
        long long cnt = 0;
        for (auto it = diff.begin(); it != diff.end(); it++) {
            // Find the smallest j that is greater than -diff[i]
            cnt += diff.end() - upper_bound(next(it), diff.end(), -(*it));
        }
        return cnt;
    }
};