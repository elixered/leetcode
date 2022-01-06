class Solution {
public:
    // int floor(vector<int>& nums, int target)
    // {
    //     int ans = -1;
    //     int low = 0;
    //     int high = nums.size()-1;
    //     while(low<=high)
    //     {
    //         int mid = low + (high-low)/2;
    //         if(nums[mid] == target)
    //         {
    //             ans = mid;
    //             high = mid-1;
    //         }
    //         else if(nums[mid]<target)
    //             low = mid+1;
    //         else
    //             high = mid-1;
    //     }
    //     return ans;
    // }
    // int ceil(vector<int>& nums, int target)
    // {
    //     int ans = -1;
    //     int low = 0;
    //     int high = nums.size()-1;
    //     while(low<=high)
    //     {
    //         int mid = low + (high-low)/2;
    //         if(nums[mid] == target)
    //         {
    //             ans = mid;
    //             low = mid+1;
    //         }
    //         else if(nums[mid]<target)
    //             low = mid+1;
    //         else
    //             high = mid-1;
    //     }
    //     return ans;
    // }
    vector<int> searchRange(vector<int>& nums, int target) {
        auto lower = lower_bound(nums.begin(),nums.end(),target);
        auto upper = upper_bound(nums.begin(),nums.end(),target);
        int start = -1, end = -1;
        if(lower != nums.end() && *lower==target)
            start = lower-nums.begin();
        if(upper != nums.begin())
            upper--;
        if(upper!=nums.end() && *upper==target)
            end = upper-nums.begin();
        return {start,end};
    }
};