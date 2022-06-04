class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size();
        vector<bool> minimum(n);
        int mini = nums[n-1];
        int maximum = nums[0];
        for(int i=n-2; i>-0; i--)
        {
            if(mini <= nums[i])
                minimum[i] = false;
            else minimum[i] = true;
            mini = min(mini,nums[i]);
        }
        int ans = 0;
        for(int i=1; i<n-1; i++)
        {
            if(nums[i]>maximum && minimum[i])
                ans+=2;
            else if(nums[i]>nums[i-1] && nums[i]<nums[i+1])
                ans+=1;
            maximum = max(maximum,nums[i]);
        }
        return ans;
    }
};