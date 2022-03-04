class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        for(int i=n-1; i>=0; i--)
        {
            int j = i+1;
            while(j<n && nums[i]>=nums[j])
            {
                if(ans[j] > 0)
                    j += ans[j];
                else j = n;
            }
            if(j<n)
                ans[i] = j-i;
        }
        return ans;
    }
};