class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int idx = n-2;
        while(idx>=0 && nums[idx]>=nums[idx+1])
            idx--;
        if(idx<0)
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        int s_idx = n-1;
        while(s_idx>idx && nums[s_idx]<=nums[idx])
            s_idx--;
        swap(nums[s_idx],nums[idx]);
        reverse(nums.begin()+idx+1,nums.end());
        return ;
    }
};