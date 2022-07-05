class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> swap(n,1e9), no_swap(n,1e9);
        swap[0] = 1;
        no_swap[0] = 0;
        for(int i=1; i<n; ++i){
            for(int j=0; j<2; ++j){
                if(nums1[i] > nums1[i-1] && nums2[i] > nums2[i-1]){
                    no_swap[i] = no_swap[i-1];
                    swap[i] = swap[i-1]+1;
                }
                if(nums1[i] > nums2[i-1] && nums2[i] > nums1[i-1]){
                    no_swap[i] = min(swap[i-1],no_swap[i]);
                    swap[i] = min(swap[i],no_swap[i-1]+1);
                }
            }
        }
        return min(swap[n-1],no_swap[n-1]);
    }
};