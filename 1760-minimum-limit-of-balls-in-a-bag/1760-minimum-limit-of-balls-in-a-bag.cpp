class Solution {
public:
    int count(vector<int>& nums, int limit)
    {
        int ans = 0;
        for(auto it:nums)
        {
            if(it<=limit) continue;
            int curr = (limit+it-1)/limit;
            ans += curr-1;
        }
        return ans;
    }
    int minimumSize(vector<int>& nums, int ops) {
        int low = 1;
        int ans = *max_element(nums.begin(),nums.end());
        int high = ans;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(count(nums,mid) <= ops)
            {
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};