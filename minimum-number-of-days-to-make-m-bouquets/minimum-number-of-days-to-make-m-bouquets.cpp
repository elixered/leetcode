class Solution {
public:
    
    bool canMake(vector<int>& nums, int boqs, int k, int days)
    {
        int n = nums.size();
        int ans = 0;
        int count = 0;
        for(int i=0; i<n; i++)
        {
            if(nums[i]<=days)
            {
                count++;
                if(count == k)
                {
                    ans++;
                    count = 0;
                }
            }
            else
            {
                count = 0;
            }
        }
        return ans >= boqs;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        int high = *max_element(bloomDay.begin(),bloomDay.end());
        int low = 0;
        int ans = -1;
        
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(canMake(bloomDay,m,k,mid))
            {
                ans = mid;
                high = mid-1;
            }
            else
                low = mid+1;
        }
        return ans;
    }
};