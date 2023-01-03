class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int ans = 0;
        int req = 0;
        for(auto it:nums){
            ans += max(req - it,0);
            req = max(req,it)+1;
        }
        return ans;
    }
};