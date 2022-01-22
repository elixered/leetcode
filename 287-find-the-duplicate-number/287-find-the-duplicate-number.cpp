class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            int dest = nums[i]-1;
            if(nums[i]==nums[dest])
                continue;
            swap(nums[i--],nums[dest]);
        }
        return nums.back();
    }
};