class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int n = nums.size();
        bool deleted = false;
        int pre_idx = 0;
        for(int i=1; i<n; i++)
        {
            if(nums[pre_idx] < nums[i])
            {
                pre_idx = i;
                continue;
            }
            if(deleted) return false;
            deleted = true;
            if(i-1>0)
            {
                if(nums[i-2] < nums[i])
                    pre_idx = i;
            }
            else pre_idx = i;
        }
        return true;
    }
};