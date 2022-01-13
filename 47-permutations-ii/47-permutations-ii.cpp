class Solution {
public:
    
    void solve(vector<vector<int>>&ans, int begin,vector<int> nums)
    {
        if(begin>=nums.size())
        {
            ans.push_back(nums);
            return;
        }
        
        for(int i=begin; i<nums.size(); i++)
        {
            if(i>begin && nums[i]==nums[begin]) continue;
            swap(nums[begin],nums[i]);
            solve(ans,begin+1,nums);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        solve(ans,0,nums);
        return ans;
    }
};