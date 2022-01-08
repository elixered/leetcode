class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        if(n<=1)
            return nums;
        int res = 1;
        vector<int> ans(n);
        for(int i=0; i<n; i++)
        {
            ans[i] = res;
            res *= nums[i];
        }
        res = 1;
        for(int i=n-1; i>=0; i--)
        {
            ans[i] *= res;
            res *= nums[i];
        }
        return ans;
    }
};