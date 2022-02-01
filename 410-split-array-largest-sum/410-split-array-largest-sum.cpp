class Solution {
public:
    
    int check(vector<int>& nums, int maxi, int m)
    {
        int count = 0;
        int curr = 0;
        for(auto it:nums)
        {
            if(curr+it<=maxi)
                curr+=it;
            else
            {
                count++;
                curr = it;
            }
        }
        return count+1;
    }
    
    int splitArray(vector<int>& nums, int m) {
        int low = *max_element(nums.begin(),nums.end());
        int high = pow(10,9);
        int ans = 0;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            cout<<mid<<"\n";
            if(check(nums,mid,m)<=m)
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