class Solution {
public:
    int findSpecialInteger(vector<int>& nums) {
        int n = nums.size();
        if(n<4) return nums[0];
        vector<int> cand = {n/4,2*n/4,3*n/4};
        for(auto i:cand)
        {
            int curr = nums[i];
            int max = upper_bound(nums.begin(),nums.end(),curr)-nums.begin()-1;
            int min = lower_bound(nums.begin(),nums.end(),curr) - nums.begin();
            if(max-min+1 > n/4) return curr;
        }
        return -1;
    }
};