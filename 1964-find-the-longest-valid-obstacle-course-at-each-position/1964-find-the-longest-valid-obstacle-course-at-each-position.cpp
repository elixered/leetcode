class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis;
        vector<int> ans(n);
        for(int i=0; i<n; i++)
        {
            if(lis.empty() || nums[i]>=lis.back())
            {
                lis.push_back(nums[i]);
                ans[i] = lis.size();
            }
            else
            {
                auto idx = upper_bound(lis.begin(), lis.end(), nums[i]) - lis.begin();
                lis[idx] = nums[i];
                ans[i] = idx+1;
            }
        }
        return ans;
    }
};