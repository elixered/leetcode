class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int curr_max = nums[0];
        int possible_max = nums[0];
        int n = nums.size();
        int ans = 1;
        for(int i=1; i<n-1; i++)
        {
            if(nums[i]<curr_max)
            {
                curr_max = possible_max;
                ans = i+1;
            }
            else
            {
                possible_max = max(possible_max,nums[i]);
            }
        }
        return ans;
    }
};