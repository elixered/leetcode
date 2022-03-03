class Solution {
public:
    int findSpecialInteger(vector<int>& nums) {
        int n = nums.size();
        if(n<4) return nums[0];
        int tf = n/4-1;
        for(int i=0; i<4; i++)
        {
            int curr = nums[tf];
            int max = upper_bound(nums.begin(),nums.end(),curr)-nums.begin()-1;
            int min = lower_bound(nums.begin(),nums.end(),curr) - nums.begin();
            if(max-min+1 > n/4) return curr;
            tf += n/4;
        }
        return -1;
    }
};