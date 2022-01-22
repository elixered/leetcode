class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            int dest = nums[i]-1;
            while(i!=dest)
            {
                if(nums[i]==nums[dest]) return nums[i];
                swap(nums[i],nums[dest]);
                dest = nums[i]-1;
            }
        }
        return nums.back();
    }
};