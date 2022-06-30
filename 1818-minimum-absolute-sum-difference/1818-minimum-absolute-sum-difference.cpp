class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        set<int> st(begin(nums1),end(nums1));
        long n = size(nums1), sum = 0, diff = 0;
        int m = pow(10,9) + 7;
        for(int i=0; i<n; ++i){
            sum += abs(nums1[i]-nums2[i]);
            auto itr = st.lower_bound(nums2[i]);
            long curr = abs(nums2[i]-nums1[i]);
            if(itr != end(st)){
                long currdiff = abs(*itr-nums2[i]);
                diff = max(diff,curr-currdiff);
            }
            if(itr != begin(st)){
                itr--;
                long currdiff = abs(*itr - nums2[i]);
                diff = max(diff,curr-currdiff);
            }
        }
        return (sum-diff)%m;
    }
};