class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
        int low=1,high=nums.size()-2;
        int n = nums.size();
        if(nums[0]>nums[1])
            return 0;
        if(nums[n-1]>nums[n-2])
            return n-1;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1])
                return mid;
            else if(nums[mid]<nums[mid-1])
                high = mid-1;
            else
                low = mid+1;
        }
        return -1;
    }
};