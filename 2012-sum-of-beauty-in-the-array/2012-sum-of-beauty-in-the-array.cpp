class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size();
        vector<int> maximum = nums, minimum = nums;
        for(int i=1; i<n; i++)
        {
            maximum[i] = max(maximum[i-1],maximum[i]);
            minimum[n-i-1] = min(minimum[n-1-i],minimum[n-i]);
        }
        int ans = 0;
        for(int i=1; i<n-1; i++)
        {
            if(nums[i]>maximum[i-1] && nums[i]<minimum[i+1])
                ans+=2;
            else if(nums[i]>nums[i-1] && nums[i]<nums[i+1])
                ans+=1;
        }
        return ans;
    }
};