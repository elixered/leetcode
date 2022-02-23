class Solution {
public:
    
    int dfs(vector<int>& nums, int l, int r)
    {
        if(l>r) return 0;
        
        int a = nums[l] + min(dfs(nums,l+2,r),dfs(nums,l+1,r-1));
        int b = nums[r] + min(dfs(nums,l+1,r-1),dfs(nums,l,r-2));
        
        return max(a,b);
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        if(n%2==0) return true;
        int sum = accumulate(nums.begin(),nums.end(),0);
        int mybest = dfs(nums,0,n-1);
        return mybest >= sum-mybest;
    }
};