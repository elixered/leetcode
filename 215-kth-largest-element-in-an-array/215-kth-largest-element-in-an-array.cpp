class Solution {
public:
    
    int partition(int i, int j, vector<int>& nums, int k)
    {
        int pivot = nums[j];
        int low = i-1;
        for(int high=i; high<j; high++)
        {
            if(nums[high]<=pivot)
            {
                low++;
                swap(nums[low],nums[high]);
            }
        }
        low++;
        swap(nums[low],nums[j]);
        return low;
    }
    
    int solve(int i,int j, vector<int>& nums, int k)
    {
        if(i>j)
            return -1;
        int idx = partition(i,j,nums,k);
        if(idx==k) return nums[k];
        else if(k>idx)
            return solve(idx+1,j,nums,k);
        else return solve(i,idx-1,nums,k);
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        return solve(0,n-1,nums,n-k);
    }
};