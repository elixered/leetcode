class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans = 0;
        int need = 0;
        for(auto it:nums)
        {
            ans += max(need-it,0);
            need = max(it,need)+1;
        }
        return ans;
    }
};