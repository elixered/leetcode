class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int n = nums.size();
        int ans = 0;
        set<int> taken;
        taken.insert(nums[0]);
        for(int i=1; i<n; ++i){
            if(taken.count(nums[i])){
                int x = *taken.rbegin() - nums[i] + 1;
                taken.insert(nums[i] + x);
                ans += x;
            }
            else
                taken.insert(nums[i]);
        }
        return ans;
    }
};