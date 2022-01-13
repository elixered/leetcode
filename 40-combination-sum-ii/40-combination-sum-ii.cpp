class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& nums, vector<int>& temp, int target, int start)
    {
        if(target<0)
            return;
        if(target==0)
            ans.push_back(temp);
        for(int i=start; i<nums.size(); i++)
        {
            if(i>start && nums[i]==nums[i-1]) continue;
            temp.push_back(nums[i]);
            solve(nums,temp,target-nums[i],i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> temp;
        solve(candidates,temp,target,0);
        return ans;
    }
};