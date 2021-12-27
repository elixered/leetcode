class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        int low = 0;
        int high = n-1;
        if(nums[low]<nums[high])
            return nums[low];
        while(low <= high)
        {
            int mid = low + (high-low)/2;
            if(mid>0 && nums[mid]<nums[mid-1])
                return nums[mid];
            else if(mid<n-1 && nums[mid]>nums[mid+1])
                return nums[mid+1];
            else
                if(nums[low]<nums[mid])
                    low = mid+1;
            else
                high = mid-1;
        }
        return nums[low];
    }
};