class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> presum(n);
        presum[0] = nums[0];
        for(int i=1; i<n; i++)
            presum[i] = presum[i-1]+nums[i];
        int ans = -1;
        if(presum[n-1]-nums[0]==0) return 0;
        for(int i=1; i<n; i++)
        {
            if(presum[i-1]==presum[n-1]-presum[i])
                return i;
        }
        return -1;
    }
};