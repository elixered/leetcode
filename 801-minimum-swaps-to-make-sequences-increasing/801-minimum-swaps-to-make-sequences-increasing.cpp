class Solution {
public:
    int dp[100001][2];
    int solve(vector<int>& nums1, vector<int>& nums2, int idx, bool swapped){
        if(idx == nums1.size()) return 0;
        if(dp[idx][swapped] != -1) return dp[idx][swapped];
        int ans = 1e5;
        if(idx==0 or nums1[idx] > nums1[idx-1] && nums2[idx] > nums2[idx-1])
            ans = solve(nums1,nums2,idx+1,false);
        if(idx==0 or nums1[idx] > nums2[idx-1] && nums2[idx] > nums1[idx-1]){
            swap(nums1[idx],nums2[idx]);
            ans = min(ans,solve(nums1,nums2,idx+1,true)+1);
            swap(nums1[idx],nums2[idx]);
        }
        return dp[idx][swapped] = ans;
    }
    
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof(dp));
        return solve(nums1,nums2,0,false);
    }
};