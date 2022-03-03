class Solution {
public:
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis;
        for(int i=0; i<n; i++)
        {
            if(lis.empty() or nums[i]>lis.back())
                lis.push_back(nums[i]);
            else
            {
                auto idx = lower_bound(lis.begin(), lis.end(), nums[i]) - lis.begin();
                lis[idx] = nums[i];
                    
            }
        }
        return lis.size();
    }
};