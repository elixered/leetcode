class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int mod = pow(10,9)+7;
        int n = nums.size();
        vector<int> power(n);
        power[0] = 1;
        for(int i=1; i<n; i++)
            power[i] = (power[i-1]*2)%mod;
        int low = 0;
        int high = nums.size()-1;
        int ans = 0;
        while(low<=high)
        {
            if(nums[low]+nums[high]>target)
                high--;
            else
            {
                ans = (ans+power[high-low])%mod;
                low++;
            }
        }
        return ans;
    }
};