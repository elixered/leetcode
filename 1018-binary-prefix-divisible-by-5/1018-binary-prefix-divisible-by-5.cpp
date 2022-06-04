class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        long long x = 0;
        vector<bool> ans;
        for(int i=0; i<nums.size(); i++)
        {
            x = x*2+nums[i];
            ans.push_back(x%5==0);
            x = x%5;
        }
        return ans;
    }
};