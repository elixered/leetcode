class Solution {
public:
    
    int bound(vector<int>& nums, int mx)
    {
        int i=0,j=0;
        int n = nums.size();
        int ans = 0;
        int maxi = -1;
        while(j<n)
        {
            maxi = max(maxi,nums[j]);
            if(maxi<=mx)
            {
                ans += j-i+1;
                j++;
            }
            else
            {
                maxi = -1;
                j++;
                i=j;
            }
        }
        return ans;
    }
    
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        return bound(nums,right) - bound(nums,left-1);
    }
};