class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]>nums[low])
            {
                if(nums[low]<=target && target<nums[mid])
                    high = mid-1;
                else
                    low = mid+1;
            }
            else if(nums[mid]<nums[high])
            {
                if(nums[mid]<target && target<=nums[high])
                    low = mid+1;
                else
                    high = mid-1;
            }
            else low++;
        }
        return -1;
    }
};