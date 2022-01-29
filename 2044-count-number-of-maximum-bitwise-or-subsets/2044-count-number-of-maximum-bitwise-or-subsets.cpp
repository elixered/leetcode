class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        const int total = 1<<n;
        int maxi = 0;
        for(auto& it:nums)
            maxi = maxi|it;
        int count = 0;
        vector<int> dp(total,0);
        for(int bitmask=1; bitmask<total; ++bitmask)
        {
            int lowbit;
            for(int i=0; i<32; i++)
            {
                if((bitmask&(1<<i))!=0)
                {
                    lowbit = i;
                    break;
                }
            }
            dp[bitmask] = dp[(bitmask&~(1<<lowbit))] | nums[lowbit];
            if(dp[bitmask]==maxi)
                count++;
        }
        return count;
    }
};