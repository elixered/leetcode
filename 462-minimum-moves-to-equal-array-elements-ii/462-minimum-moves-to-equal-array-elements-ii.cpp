class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans = 0;
        int n = nums.size();
        int low=0,high=n-1;
        while(low<=high)
        {
            ans += nums[high--]-nums[low++];
        }
        return ans;
    }
};