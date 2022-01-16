class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans = 0;
        int n = nums.size();
        int median = nums[n/2];
        for(auto it:nums)
            ans += abs(it-median);
        return ans;
    }
};