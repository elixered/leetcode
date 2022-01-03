class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        if(n<=1)
            return nums;
        vector<int> prefix(n),suffix(n);
        prefix[0] = nums[0];
        suffix[n-1] = nums[n-1];
        for(int i=1; i<n; i++)
            prefix[i] = nums[i]*prefix[i-1];
        for(int i=n-2; i>=0; i--)
            suffix[i] = nums[i]*suffix[i+1];
        vector<int> ans(n);
        for(int i=0; i<n; i++)
        {
            int curr = 1;
            if(i-1>=0)
                curr*=prefix[i-1];
            if(i+1<n)
                curr *= suffix[i+1];
            ans[i] = curr;
                
        }
        return ans;
    }
};