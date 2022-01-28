class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& nums) {
        int n = nums.size();
        int i=0, j = n-1;
        while(i<n-1 && nums[i]<=nums[i+1])
            i++;
        while(j>0 && nums[j]>=nums[j-1])
            j--;
        if(j<=i)
            return 0;
        int ans = min(n-i-1,j);
        int low = 0;
        int high = j;
        while(low<=i && high<n)
        {
            if(nums[low]<=nums[high])
            {
                ans = min(ans,high-low-1);
                low++;
            }
            else
                high++;
        }
        return ans;
    }
};