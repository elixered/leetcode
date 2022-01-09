class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int ones = 0;
        for(auto it:nums)
            ones+=it;
        int n = nums.size();
        int res = ones;
        int count = 0;
        for(int i=0,j=0; i<n; i++)
        {
            while(j-i+1<=ones)
            {
                count += nums[j%n];
                j++;
            }
            res = min(res,ones-count);
            count -= nums[i];
        }
        return res;
    }
};