class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int total = 1<<n;
        int maxi = 0;
        for(auto& it:nums)
            maxi = maxi|it;
        int count = 0;
        for(int bitmask=1; bitmask<total; bitmask++)
        {
            int temp = 0;
            for(int i=0; i<n; i++)
            {
                if((bitmask&(1<<i))!=0)
                    temp = temp|nums[i];
            }
            if(temp==maxi)
                count++;
        }
        return count;
    }
};