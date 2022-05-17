class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum = INT_MIN;
        int currsum = 0;
        for(auto n:nums)
        {
            currsum += n;
            maxsum = max(maxsum,currsum);
            currsum = max(currsum,0);
        }
        return maxsum;
    }
};