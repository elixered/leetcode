class Solution {
public:
    
    void solve(vector<vector<int>>& ans, vector<int> nums, vector<int>& temp, int idx)
    {
        ans.push_back(temp);
        if(idx>=nums.size()) return;
        for(int i=idx; i<nums.size(); i++)
        {
            if(i>idx && nums[i]==nums[i-1]) continue;
            temp.push_back(nums[i]);
            solve(ans,nums,temp,i+1);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        solve(ans,nums,temp,0);
        return ans;
    }
};