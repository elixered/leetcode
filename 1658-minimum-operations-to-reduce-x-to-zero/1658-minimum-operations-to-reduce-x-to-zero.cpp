class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        if(x==0) return 0;
        int sum = 0;
        int n = nums.size();
        for(auto& it:nums)
            sum += it;
        sum -= x;
        if(sum==0) return n;
        int ans = 0;
        int i=0,j=0;
        int currSum = 0;
        while(j<n)
        {
            currSum += nums[j];
            while(i<=j && currSum>sum)
            {
                currSum -= nums[i++];
            }
            if(currSum==sum)
            {
                ans = max(ans,j-i+1);
            }
            j++;
        }
        return ans==0?-1:n-ans;
    }
};