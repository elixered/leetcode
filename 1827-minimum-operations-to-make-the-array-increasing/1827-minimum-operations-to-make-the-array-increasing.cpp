class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        int last = nums[0];
        for(int i=1; i<nums.size(); i++)
        {
            ans += max(0,last-nums[i]+1);
            last = max(last+1,nums[i]);
        }
        return ans;
    }
};