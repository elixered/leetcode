class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxi = nums[0];
        int curr_max = nums[0];
        if(curr_max<0)
            curr_max = 0;
        int n = nums.size();
        int mini = nums[0];
        int curr_min = nums[0];
        if(curr_min>0)
            curr_min = 0;
        int t = nums[0];
        for(int i=1; i<n; i++)
        {
            t += nums[i];
            maxi = max(curr_max+nums[i],maxi);
            curr_max = max(curr_max+nums[i],0);
            mini = min(curr_min+nums[i],mini);
            curr_min = min(curr_min+nums[i],0);
        }
        cout<<t<<" "<<maxi<<" "<<mini;
        if(t==mini)
            return maxi;
        else return max(maxi,t-mini);
    }
};